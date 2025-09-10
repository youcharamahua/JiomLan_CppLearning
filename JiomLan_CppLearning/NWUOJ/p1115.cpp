#include <bits/stdc++.h>
using namespace std;

int n,tempn;
int num[100005];
bool ju = true;
int main(){
	const char endl = '\n';
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < 2*n ; i++){
		cin >> tempn;
		num[tempn]++; 
	}
	for(int i = 0; i <= 100000 ; i++){
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

