#include <iostream>
using namespace std;

int a;
int daycount = 1;
int main(){
	cin >> a;
	while(a!=1){
		a = a/2;
		daycount ++;
	}
	cout<<daycount;
	
	
	
	return 0;
} 
