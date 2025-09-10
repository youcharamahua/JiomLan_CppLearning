#include <bits/stdc++.h>
using namespace std;

double x,a,y,b,z;
int main(){
	const char endl = '\n';
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>a>>y>>b;
	cout<<fixed<<setprecision(2)<<(x*a-y*b)/(a-b)<<endl;
	return 0;
}
