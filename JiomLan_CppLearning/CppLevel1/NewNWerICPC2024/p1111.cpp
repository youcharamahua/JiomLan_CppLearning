/*
============================================================
题意(整理后的口语化版本)：
============================================================
有 n 张卡牌（编号 1..n），第 i 张卡牌当前的战斗力是 a[i]。
两位玩家：OMoonStars（先手） 与 FantasyT（后手），轮流从“剩余的所有卡牌”中任意挑一张加入自己的手牌，
直到所有卡牌被拿完。双方都采用最优策略。谁手牌总战斗力和大，则获胜；相等就是平局。

接着有 q 次“版本更新”，每次把某一张卡牌的战斗力永久改成一个新值。每次更新后，都要立即
回答：若此时重新从头开始用“最优策略”抓牌，谁会赢（或平局）。

============================================================
核心结论（博弈分析 —— 新手重点）：
============================================================
因为玩家可以从“任意剩余卡牌”里挑（不是只能拿最上/最左/两端等限制），那么双方在最优策略下，
第一回合先手一定会拿当前所有卡牌里“最大的”那张。随后后手也会在剩下卡里拿“最大的”。
继续这样，你会发现两个人只是按“从大到小排序”的顺序，交替拿牌：
  排序后：v1 >= v2 >= v3 >= ... >= vn
  先手得到：v1, v3, v5, ... （所有奇数下标）
  后手得到：v2, v4, v6, ... （所有偶数下标）
因此胜负只取决于：排序后奇数位总和 与 偶数位总和 的比较。

我们需要支持 q 次单点修改：修改某个位置的值，然后快速得出：
   D = (v1 + v3 + v5 + ...) - (v2 + v4 + v6 + ...)
   若 D > 0 先手胜；D < 0 后手胜；D == 0 平局。

============================================================
如何快速维护 D（难点 & 讲解）：
============================================================
直接排序每次 O(n log n) 会超时 (n,q 可以很大)。必须用数据结构支持“动态集合 + 按降序的交替加减”。

关键观察：把所有值按降序排成一条线。我们只关心“交替 + - + - ...” 的加权和。
对于“相同数值”的若干重复项（设值为 x、出现次数为 c），它们会占据一段连续位置。
这段里若 c 是偶数，则它的贡献会“正负抵消成 0”；若 c 是奇数，则只会留下 1 个 x 的净贡献，
而且符号取决于这段起始位置是奇还是偶。

再进一步：设所有不同的数值（降序）为 x1 > x2 > ... > xm，计数为 c1,c2,...,cm。
令 prefixParity_i = (c1 + c2 + ... + c_{i-1}) mod 2，表示在 xi 之前总共有多少张牌（取奇偶）。
如果 ci 是奇数，那么 xi 的贡献 sign*xi 里 sign = +1 当 prefixParity_i == 0，否则 -1。
如果 ci 是偶数，则对最终 D 无贡献。

于是我们只需要一棵支持以下维护的平衡树：按 key = 值 降序存储；每个节点维护：
  (1) 子树里所有牌张数的 parity(奇偶)；
  (2) 在“前缀奇偶 = 0” 和 “前缀奇偶 = 1” 两种假设下，该子树的 D 值（分别记作 d0, d1）。
根节点的 d0 就是整个集合真正的 D（因为最开始前缀为空，即前缀奇偶=0）。

为什么要同时存 d0 / d1？
  因为当我们把一个子树挂到更大结构时，它前面已经有若干元素了（可能是偶数个也可能是奇数个）。
  若前面总数是偶数 -> 这个子树内部“第1个”仍是全局奇数位；否则翻转。
  所以需要提前知道两种情况下的结果，组合时 O(1) 计算。

我们用 Treap（随机优先级BST）实现，节点字段：
  val: 数值
  cnt: 出现次数
  parity: 该节点整棵子树牌总数的奇偶（0/1）
  d0, d1: 上述解释
  l, r, priority: Treap 标准内容

更新公式（核心再解释给新手）：
  设左子树为 L，右子树为 R，当前节点计数 cnt。
  对某个“进入当前子树时”的前缀奇偶 p（0/1），
	1) 先拿左子树贡献: D_left = (p==0 ? L.d0 : L.d1)
	2) 计算经过左子树后的奇偶 p_after_left = p XOR L.parity
	3) 当前值贡献: 如果 cnt 是奇数，贡献 = (p_after_left==0 ? +val : -val)，否则 0
	4) 经过当前值后的奇偶 p_after_node = p_after_left XOR (cnt & 1)
	5) 右子树贡献: D_right = (p_after_node==0 ? R.d0 : R.d1)
	总和 = D_left + 当前 + D_right
  分别把 p=0 的结果存 d0，p=1 的结果存 d1。

============================================================
使用步骤：
  1. 建树：把初始 n 个值依次 insert（出现次数累加）。
  2. 每次修改：拿到下标 pos 的旧值 old，执行 add(old, -1)，再 add(newValue, +1)。
  3. 根的 d0 即当前 D，判断正负输出答案。

时间复杂度：每次插入/删除 O(log M)（M = 不同值数量），总体 O((n + q) log M)。

============================================================
下面是详细注释的代码（力求适合新手循序阅读）。
============================================================
*/

#include <iostream>
#include <vector>
// 为兼容评测机的 g++ 9.4.0 -std=c++14 --static，我们不用 <random>/<chrono>，改用简单 xorshift64 伪随机。
using namespace std;

// 简单 xorshift 伪随机（足够随机即可，不要求强随机性）
static unsigned long long __seed = 1145141919ULL;
static inline unsigned next_rand(){
	unsigned long long x = __seed;
	x ^= x << 7;
	x ^= x >> 9;
	x ^= x << 13;
	__seed = x;
	return (unsigned)(x & 0xffffffffu);
}

// Treap 节点结构
struct Node {
	long long val;     // 该节点代表的数值
	int cnt;           // 该数值出现次数
	int parity;        // 子树内所有牌总数 (mod 2) 的结果 (0=偶,1=奇)
	long long d0;      // 假设进入本子树前“已拿的牌数量”为偶数时，本子树对 D 的贡献
	long long d1;      // 假设进入本子树前“已拿的牌数量”为奇数时，本子树对 D 的贡献
	Node *l, *r;       // 左右子树
	unsigned pri;      // Treap 的随机优先级
	Node(long long v, unsigned p): val(v), cnt(1), parity(1), d0(0), d1(0), l(nullptr), r(nullptr), pri(p) {}
};

// 获取子树 d0/d1 或 parity 的安全函数（空指针返回0）
inline int getParity(Node* t){ return t ? t->parity : 0; }
inline long long getD0(Node* t){ return t ? t->d0 : 0LL; }
inline long long getD1(Node* t){ return t ? t->d1 : 0LL; }

// 重新计算节点 t 的 parity, d0, d1
void pull(Node* t){
	if(!t) return;
	// 先更新 parity：= 左子树牌数奇偶 XOR (当前 cnt 奇偶) XOR 右子树牌数奇偶
	// 注意：cnt 可能 >1，我们只关心它奇偶，所以 (cnt & 1)
	int lp = getParity(t->l);
	int rp = getParity(t->r);
	int selfOdd = (t->cnt & 1); // 当前值出现次数的奇偶
	t->parity = (lp ^ selfOdd ^ rp); // XOR == 加法模2

	// 下面分别计算 d0 和 d1
	// 封装一个 lambda，输入 prefixParity(进入该子树前的已放牌数量奇偶) -> 返回总贡献
	auto calc = [&](int prefixParity)-> long long {
		// 1) 左子树
		long long leftD = (prefixParity == 0 ? getD0(t->l) : getD1(t->l));
		int afterLeft = prefixParity ^ lp; // 经过左子树后的奇偶
		// 2) 当前节点自身净贡献（只有 cnt 为奇数才会留下一个 val）
		long long selfD = 0;
		if(selfOdd){
			selfD = (afterLeft == 0 ? +t->val : -t->val);
		}
		int afterNode = afterLeft ^ selfOdd; // 再经过当前值
		// 3) 右子树
		long long rightD = (afterNode == 0 ? getD0(t->r) : getD1(t->r));
		return leftD + selfD + rightD;
	};
	t->d0 = calc(0);
	t->d1 = calc(1);
}

// 右旋 / 左旋：Treap 核心（保持 BST + 堆性质）
// 这里用 split / merge 更简洁；但对“按键插入”我们可以直接递归插入然后旋转。

// 旋转写法（可选）。这里我采用更直接的 split/merge 写法以简化逻辑。

// 按 key 拆分：把 t 按 <= key 与 > key 分为两棵树，放进 a,b
void split(Node* t, long long key, Node* &a, Node* &b){
	if(!t){ a = b = nullptr; return; }
	if(t->val <= key){ // 注意：我们希望总体上“降序”，但更常用做法是 BST 升序；最后用的时候小心即可。
		split(t->r, key, t->r, b);
		a = t;
		pull(a);
	}else{
		split(t->l, key, a, t->l);
		b = t;
		pull(b);
	}
}

// 合并：所有 a 的 key <= 所有 b 的 key
Node* merge(Node* a, Node* b){
	if(!a) return b;
	if(!b) return a;
	if(a->pri < b->pri){ // 小优先级当根（常见写法）
		a->r = merge(a->r, b);
		pull(a);
		return a;
	}else{
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}

// 在 Treap 中增加某个值 val (delta=+1 或 -1)
void add(Node* &root, long long val, int delta){
	// 先把 <= val 与 > val 分开
	Node *A, *B; split(root, val, A, B);
	Node *A1, *mid; split(A, val-1, A1, mid); // mid 中的值都 == val (或空)
	if(delta > 0){
		if(!mid){ // 新建
			mid = new Node(val, next_rand());
			mid->cnt = delta; // 初始次数 delta (一般为1)
		}else{
			mid->cnt += delta; // 累加
		}
	}else if(delta < 0){
		if(!mid){
			// 要删的值不存在：题目保证合法更新，这里不处理错误
		}else{
			mid->cnt += delta; // 减少次数
			if(mid->cnt <= 0){ // 次数为 0：删除节点
				delete mid; mid = nullptr;
			}
		}
	}
	if(mid) pull(mid);
	root = merge(merge(A1, mid), B);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q; // n: 初始卡牌数, q: 更新次数
	if(!(cin >> n >> q)) return 0; // 防止空输入
	vector<long long> a(n+1); // a[i] 存放第 i 张卡牌当前战斗力
	for(int i=1;i<=n;i++) cin >> a[i];

	// 初始化 Treap
	Node* root = nullptr;
	for(int i=1;i<=n;i++) add(root, a[i], +1);

	// 处理 q 次更新
	while(q--){
		int pos; long long v; // 把第 pos 张卡牌的战斗力改为 v
		cin >> pos >> v;
		long long old = a[pos];
		if(old == v){
			// 不变，直接输出当前结果
		}else{
			add(root, old, -1); // 删除旧值一次
			add(root, v, +1);   // 插入新值一次
			a[pos] = v;          // 更新数组
		}
		long long D = root ? root->d0 : 0; // 当前差值 (奇数位总和 - 偶数位总和)
		if(D > 0) cout << "OMoonStars\n";
		else if(D < 0) cout << "FantasyT\n";
		else cout << "Draw\n";
	}

	return 0;
}

/*
==========================
再补一个极简示例帮助理解：
初始： 5 4 4 1
排序： 5 4 4 1
先手拿: 5, 4 (?? 错) —— 注意交替：
  位置:1 2 3 4
  值:  5 4 4 1
  先手: 5 + 4(第3个) = 9
  后手: 4(第2个) + 1 = 5  => 先手赢
如果把一个 4 改成 10：集合 {10,5,4,1}
排序：10 5 4 1
先手: 10 + 4 = 14, 后手: 5 + 1 = 6 => 先手赢

你可以在心里把“交替求和”理解成：把所有数降序排，奇位加，偶位减；>0 就代表奇位(先手)占优。
==========================
*/