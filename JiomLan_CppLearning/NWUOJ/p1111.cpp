#include <bits/stdc++.h>
using namespace std;


int n,q,cid,v;
int card[100006];
int OMS = 0;
int FT = 0;

int ju(){
	sort(card+1,card+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(i%2==1){
			OMS += card[i];
		}else{
			FT += card[i];
		}
	}
	
	if(OMS > FT){
		cout<<"OMoonStars"<<endl;
	}else if(OMS < FT){
		cout<<"FantasyT"<<endl;
	}else{
		cout<<"Draw"<<endl;
	}
	return 0;
}

int main(){
	const char endl = '\n';
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i=1; i<=n ; i++){
		cin >> card[i];
	}
	for(int i=1; i<=q ; i++){
		cin >> cid >> v;
		card[cid] = v;
		ju();
	}
	
} 
