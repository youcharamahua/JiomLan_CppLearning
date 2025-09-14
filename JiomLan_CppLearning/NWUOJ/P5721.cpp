#include <iostream>
using namespace std;

int n;
int cot = 1;
int main(){
	const char endl = '\n';
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	cin>>n;
	for(int i=n;i >= 1;i--){
		for(int j=1;j<=i;j++){
			if(cot < 10){
				cout<<'0';
			}
			cout<<cot;
			cot++;
		}
		cout<<endl;
	}
	
	
	
}
