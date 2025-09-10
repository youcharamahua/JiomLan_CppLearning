#include <iostream>
using namespace std;

char c;
int main(){
	//io speed up
	const char endl = '\n';
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3-i;j++){
			cout<<" ";
		}
		for(int j=1;j<=i*2-1;j++){
			cout<<c;
		}
		cout<<endl;
	}
	return 0;
} 
