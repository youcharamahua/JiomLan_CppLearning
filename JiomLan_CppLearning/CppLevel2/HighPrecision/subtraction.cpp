#include <iostream>
using namespace std;
string a, b;
int a_n[1005];
int b_n[1005];
int c[1005];
// 高精度减法
// High-precision subtraction
int main(){
    cin >> a >> b;
    int la = a.length();
    int lb = b.length();
    if ((lb > la) || (la == lb)&&(a < b)){
        swap(a,b)
    }
    //保证a永远是更大的数字，C++中string依旧重载了比较运算
    /*
    1. 从两个字符串的第一个字符开始，依次比较每个字符的ASCII值。
    2. 如果两个字符相同，则继续比较下一个字符。
    3. 如果两个字符不同，则ASCII值较小的字符所在的字符串被认为更小。
    4. 如果一直比较到某个字符串结束，那么较短的字符串被认为更小。
    */
    // 清零数组
    for (int i = 0; i < 1005; ++i) {
        a_n[i] = b_n[i] = c[i] = 0;
    }

    for (int i = 0;i < la; i++){
        a_n[la - i] = a[i] - '0';
    }

    for (int i = 0; i < lb; i++)
    {
        b_n[lb - i] = b[i] - '0';
    }
    
    int lc = max(la, lb);
    int borrow = 0;

    for (int i = lc;i >= 0; i--)
    {
        int current = a_n[i] - b_n[i] - borrow;
        if (current < 0 ){
            current += 10;
            borrow = 1;
        }else {
            borrow = 0;
        }
        c[i] = current;
    }

    // 处理结果前导零
    while (lc > 1 && c[lc] == 0) {
        lc--;
    }

    // 输出结果
    for (int i = lc; i >= 1; i--) {
        cout << c[i];
    }
    cout << endl;
}