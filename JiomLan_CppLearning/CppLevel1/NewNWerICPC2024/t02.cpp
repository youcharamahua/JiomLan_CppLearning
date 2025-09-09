#include <bits/stdc++.h>
using namespace std;

int n,tempn;
int num[10005];
bool ju = true;
int main(){
	cin >> n;
	for(int i = 0; i < 2*n ; i++){
		cin >> tempn;
		num[tempn]++; 
	}
	for(int i = 0; i <= 10000 ; i++){
		if(num[i]%2 != 0){
			cout<<"WA";
			ju = false;
			break;
		}
	}
	if(ju){
		cout<<"AC";
	}
	
	
	return 0;
}
