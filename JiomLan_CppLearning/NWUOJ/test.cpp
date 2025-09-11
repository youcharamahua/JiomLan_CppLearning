#include <bits/stdc++.h>
using namespace std;


int n,q,cid,v;
int card[100006];
int OMS = 0;
int FT = 0;
int main(){
	const char endl = '\n';
	int c[8] = {1,0,8,4,5,6,9,2};
	sort(c+1,c+5,greater<int>());
	for(int i=0;i<=7;i++){
		cout<<c[i]<<' ';
	}
	cout << endl;
	for(int i=1;i<=5;i++){
		cout<<c[i]<<' ';
	}
	
} 
