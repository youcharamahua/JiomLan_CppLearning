#include <bits/stdc++.h>
using namespace std;

int n,m,tempn;
int stu[10000000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>stu[i];
	}
	for(int i=1;i<=m;i++){
		cin>>tempn;
		cout<<stu[tempn]<<endl;
	}
	return 0;
} 
