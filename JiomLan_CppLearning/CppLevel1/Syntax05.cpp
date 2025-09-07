//P5726 【深基4.习9】打分
#include <iostream>
using namespace std;
int n,a[10001];
double ans;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);//排序算法
	for(int i=2;i<=n-1;i++) ans+=a[i];
	printf("%.2lf",ans/(n-2));//格式化输出
	return 0;
}
