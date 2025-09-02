#include <iostream>
#include <cmath>
using namespace std;
//P2415 集合求和
/*
给定一个集合 s（集合元素数量 ≤30），求出此集合所有子集元素之和。
*/
int numset[30];
int i = 0;
long long numsum = 0;
int main(){
    while(cin>>numset[i++]);
    for (int j = 0;j < i; j++){
        numsum += numset[j];
    }
    numsum *= pow(2,i-2);
    cout<<numsum;
    return 0;
}