/*
P1048 [NOIP 2005 普及组] 采药
第一行有 2 个整数 T（1≤T≤1000）和 M（1≤M≤100），
用一个空格隔开，T 代表总共能够用来采药的时间，M 代表山洞里的草药的数目。
接下来的 M 行每行包括两个在 1 到 100 之间（包括 1 和 100）的整数，
分别表示采摘某株草药的时间和这株草药的价值。

输出在规定的时间内可以采到的草药的最大总价值。
*/

#include <iostream>
using namespace std;
int T, M;
int timelist[101], value[101];
int dp[101][1001];

int main(){
    cin >> T >> M;
    for(int i = 1; i <= M; i++){
        cin >> timelist[i] >> value[i];
    }
    for(int i = 1;i <= M; i++){
        for(int j = 0; j <= T; j++){
            dp[i][j] = dp[i-1][j];
            if( j>= timelist[i]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-timelist[i]]+value[i]);
            }
        }
    }
    cout << dp[M][T];

    return 0;
}