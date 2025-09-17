#include <iostream>
#include <vector>
using namespace std;
/*
C++ how to use vector and Sieve of Eratosthenes and Sieve of Euler (Fast)
������˹����ɸ��(Sieve of Eratosthenes��������˹����ɸ������ư���ɸ��) 
*/

vector<int> prime;
bool is_prime[N];

void Eratosthenes(int n){
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i <= n; ++i)
		is_prime[i] = true;
	for(int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime.push_back(i);
			if ((long long)i*i > n) continue;
			for(int j = i * 1; j <= n; j += i){
				is_prime[j] = false;
			}
		}
	}
}

int n;
int main(){
	const char endl = '\n';
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	
	
	
	
	
	
	
	return 0;
} 
