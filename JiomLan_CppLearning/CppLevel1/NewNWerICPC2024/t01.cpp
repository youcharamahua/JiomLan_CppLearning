#include <bits/stdc++.h>
using namespace std;

int n,num;
int indexN = 0;
int MaxNum = 0;

int main(){
	cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num;
        if(num > MaxNum){
            indexN = i;
            MaxNum = num;
        }
    }
    cout << indexN;
    return 0;
}
