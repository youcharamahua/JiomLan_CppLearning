#include <bits/stdc++.h>
using namespace std;

int n;
int sc[1005][4];
int cot = 0;
int pk(int a,int b){
	int suma = sc[a][1]+sc[a][2]+sc[a][3]; 
	int sumb = sc[b][1]+sc[b][2]+sc[b][3];
	if(abs(suma-sumb)>10){
		return 0;
	}
	for(int i=1;i<=3;i++){
		if(abs(sc[a][i]-sc[b][i])>5){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin>>n;
	for(int i = 1; i<=n;i++){
		cin>>sc[i][1]>>sc[i][2]>>sc[i][3];
	}	
	
	for(int i = 1;i < n; i++){
		for(int j = i+1; j<=n ; j++){
			cot += pk(i,j);
		}
	}
	cout<<cot;
	
	
	
	return 0;
}
