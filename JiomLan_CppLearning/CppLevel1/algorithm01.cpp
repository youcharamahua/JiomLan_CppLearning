#include <iostream>
using namespace std;

int n;

/*
判断质数：

1. 质数的定义
首先，质数的定义是：一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数。

2. 核心思想：试除法
这个算法采用的方法叫做“试除法”（Trial Division）。
它的核心思想很直观：
既然质数只能被1和它本身整除，那么我就尝试用所有可能的小于它的数（除了1）去整除它。
如果发现任何一个数能整除它，那它就不是质数。
*/
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return x > 1;
}


/*
# P1075
已知正整数n是两个不同的质数的乘积，试求出两者中较大的那个质数。
*/
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) 
	{
		if (n % i == 0) 
		{
            //唯一分解定理:一个数能且只能分解为一组质数的乘积。
			cout << n / i << endl;
			return 0;
		}
	}
	return 0;
}