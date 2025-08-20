#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
// 不包含负数的高精度加法
// High-precision addition without negative numbers
string a, b;
int a_n[1000];
int b_n[1000];
int c[1005];

int main() {
	cin >> a >> b;
	int la = a.length();
	int lb = b.length();

	for (int i = 0;i < la;i++) {
		a_n[la - i] = a[i] - '0';
	}
	for (int i = 0;i < lb;i++) {
		b_n[lb - i] = b[i] - '0';
	}

	int lc = max(la, lb);
	for (int i = 1;i <= lc;i++) {
		c[i] += a_n[i] + b_n[i];
		c[i + 1] = c[i] / 10;
		c[i] %= 10;
	}

	if (c[lc + 1] > 0) {
		lc++;
	}
	for (int i = lc;i >= 1;i--) {
		cout << c[i];
	}

}