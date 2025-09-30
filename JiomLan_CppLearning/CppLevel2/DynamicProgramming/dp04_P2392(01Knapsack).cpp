#include<bits/stdc++.h>
using namespace std;
int a[5],i,j,k,sum,t,homework[21],dp[2501];
int main(){
    for(i=1;i<=4;i++)
        cin >> a[i]; 
    for(i=1;i<=4;i++){
    	sum = 0;
    	for(j=1;j<=a[i];j++){
    		cin >> homework[j];
			sum += homework[j];
		}
		for(j=1;j<=a[i];j++){
			for(k=sum/2;k>=homework[j];k--){
				dp[k] = max(dp[k],dp[k-homework[j]]+homework[j]);
			}				
		}
		t += sum - dp[sum/2];
		for(j=1;j<=sum/2;j++){
			dp[j] = 0;
		}
    }
    cout<<t;
    return 0;
}
