#include <iostream>
#include <queue>

//P1162 填涂颜色
using namespace std;
int Map[35][35];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,1,-1};
int n;
struct ST{
	int x;
	int y;
};
queue <ST>Q; 

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>Map[i][j];
		}
	}
	Q.push({0,0});
	while(!Q.empty()){
		ST q=Q.front();
		Q.pop();
		for(int i=1;i<=4;i++){
			int nx = q.x+dx[i];
			int ny = q.y+dy[i];
			if(0<=nx&&nx<=n+1&&0<=ny&&ny<=n+1&&Map[nx][ny]==0){
				Map[nx][ny] = 3;
				Q.push({nx,ny});
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(Map[i][j]==3){
				Map[i][j]=0;
			}else if(Map[i][j]==0){
				Map[i][j]=2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<Map[i][j]<<' ';
		}
		cout<<endl;
	}
} 
