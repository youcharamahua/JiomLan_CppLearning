#include <bits/stdc++.h>
using namespace std;

/*
不使用双向列表的模拟做法 
#include <bits/stdc++.h>
using namespace std;

int nextL[1000005];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
		nextL[i]=i+1;
	}
	nextL[n]=1;//构建循环
	 
	int p=0;
	for(int i=1;i<=n;i++){ //每一次枪毙一个人，枪毙十次就够了 
		for(int j=1;j<m;j++){
			p=nextL[p];
		}
		cout<<p[nextL]<<" ";
		nextL[p]=nextL[nextL[p]];
	}
	return 0;
	
}
*/

//double linked list 双向列表 
struct DLList{
	int data;
	DLList *prev; //指向前一个节点的指针 
	DLList *next; //指向后一个节点的指针 
	
	// 于创建新节点时初始化
    Node(int val) {
        data = val;      // 设置数据
        prev = nullptr;  // 前指针设为空
        next = nullptr;  // 后指针设为空
    }
    /* 构造函数，Node(int val) : data(val), prev(nullptr), next(nullptr) {}
	参数说明：(: 冒号表示后面是初始化列表)
     - val: 要存储的编号
     - prev: 初始化为nullptr（空指针），表示还没有前驱节点
     - next: 初始化为nullptr（空指针），表示还没有后继节点
     空的大括号表示函数体是空的，没有其他操作需要执行
    */ 
};

int n,m;
int main(){
	cin>>n>>m;
	DLList *head = new DLList(1);// 创建链表的第一个节点（编号为1的人）
	/*
	new 的具体作用
	Node* head = new DLList(1);
	这行代码做了三件事：
	分配内存：在堆（heap）上分配足够存储一个 DLList 对象的内存空间
	调用构造函数：调用 Node 类的构造函数，初始化这个内存空间
	返回指针：返回这个内存空间的地址，让你可以通过指针访问它
     - new Node(1): 在内存中分配空间创建一个新节点，编号为1
     - Node* head: 声明一个指针变量head，指向这个新创建的节点
	*/
	DLList *current = head;  // 创建一个当前指针，初始指向头节点
	
	for(int i = 2; i <= n; i++){
		DLList *newNode = new DLList(i);
		
		// 将当前节点的next指针指向新节点
		current->next = newNode;
        // 解释：
        // - current->next: 访问current指向的节点的next成员
        // - 将新节点的地址赋值给current->next
        
        // 将新节点的prev指针指向当前节点
        newNode->prev = current;
        
        // 将当前指针移动到新创建的节点，为下一次循环做准备
        current = newNode;
	}
	
	// 将链表首尾连接，形成循环链表
    current->next = head;  // 最后一个节点的next指向头节点
    head->prev = current;  // 头节点的prev指向最后一个节点
    
    // 现在链表是一个双向循环链表，所有人围成一圈
    
    current = head;  // 从第一个人开始报数
    
    // 当还有人未出圈时继续循环
    while (n > 0) {
        // 数m-1个人（因为从当前节点开始数，所以只需要数m-1次）
        for (int i = 1; i < m; i++) {
            current = current->next;  // 移动到下一个节点
        }
        
        // 当前节点就是要出圈的人
        Node *toDelete = current;  // 保存要删除的节点的指针
        
        // 输出出圈人的编号
        cout << toDelete->data << " ";
        
        // 将当前指针移动到下一个节点，为下一次报数做准备
        current = current->next;
        
        // 调整链表指针，移除要删除的节点
        toDelete->prev->next = toDelete->next;  // 前一个节点的next指向后一个节点
        toDelete->next->prev = toDelete->prev;  // 后一个节点的prev指向前一个节点
        
        // 释放被删除节点的内存
        delete toDelete;
        
        n--;  // 剩余人数减一
    }
	return 0;
} 
