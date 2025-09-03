#include <iostream>
#include <algorithm>
using namespace std;
//P1888 三角函数
/*
输入一组勾股数 a,b,c 用分数格式输出其较小锐角的正弦值。（要求约分。）
*/
int a,b,c;
int m,mid,M;
int main(){
    cin >> a >> b >> c;
    M = max(max(a,b),c);
    m = min(min(a,b),c);
    //mid = a + b + c - M - m;
    int g =__gcd(M,m);
    cout << (m/g) << "/" << (M/g);


    return 0;
}