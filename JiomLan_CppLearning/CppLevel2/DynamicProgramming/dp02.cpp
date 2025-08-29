/*
P2842 纸币问题 1
第一行两个整数 n,w，分别表示纸币的种数和要凑出的金额。
第二行一行 n 个以空格隔开的整数 a1,a2,a3,…an依次表示这 n 种纸币的面额。

一行一个整数，表示最少使用的纸币张数。
*/

#include <iostream>
using namespace std;

int n,w;
int v[1008];
int dp[10008];

int main(){
    cin >> n >> w;

    for (int i = 1;i <= 1005; i++) {
        v[i] = 0;
    }
    for (int i = 1;i <= 10005; i++){
        dp[i] = 999999999;
    } 

    for (int i = 1;i <= n; i++){
        cin >> v[i];
    }

    for (int i = 1;i <= n; i++){
        for (int j = 1;j <= w; j++){
            if (j >= v[i]){
                dp[j] = min(dp[j],dp[j-v[i]]+1);
            }
        }
    }

    cout << dp[w];

    return 0;
}