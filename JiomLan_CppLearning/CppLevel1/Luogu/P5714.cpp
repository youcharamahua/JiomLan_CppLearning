#include <bits/stdc++.h>
using namespace std;

int n;
int sc[1005][4];
string stu[1005];
int pk(int a,int b){
	int suma = sc[a][1]+sc[a][2]+sc[a][3]; 
	int sumb = sc[b][1]+sc[b][2]+sc[b][3];
	if(abs(suma-sumb)>10)return 0;
	for(int i=1;i<=3;i++) if(abs(sc[a][i]-sc[b][i])>5) return 0;
	if(stu[a]<stu[b]) cout<<stu[a]<<' '<<stu[b]<<endl;
	else cout<<stu[b]<<' '<<stu[a]<<endl;
}

int main(){
	cin>>n;
	for(int i = 1; i<=n;i++)cin>>stu[i]>>sc[i][1]>>sc[i][2]>>sc[i][3];
	for(int i = 1;i < n; i++)for(int j = i+1; j<=n ; j++) pk(i,j);
	return 0;
}



