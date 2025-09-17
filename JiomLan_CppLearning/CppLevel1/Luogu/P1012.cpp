//#include <iostream>
//#include <string>
//可以使用万能头文件 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string strs[21];
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    //字符串本质上是char类型的数组
	/*
	字典序（Lexicographical Order）是一种基于字母或字符顺序的排序方式： 
	1.从两个字符串的第一个字符开始比较
	2.如果字符相同，则继续比较下一个字符
	3.如果遇到不同的字符，则根据这两个字符的编码值（如 ASCII 码）决定顺序
	4.如果一个字符串是另一个字符串的前缀，则较短的字符串排在前面
	*/
	
	
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strs[j] + strs[j+1] < strs[j+1] + strs[j]) {
            	//进行字典序的比较
				/*
				例： 比较数字 "12" 和 "3"
				—————————— 
				"12" + "3" = "123"
				"3" + "12" = "312"
				—————————— 
				第一个字符：'1' 和 '3'，'3' 的 ASCII 码更大， 
				因此 "312" 的字典序大于 "123"， 
				所以 "3" 应该排在 "12" 前面， 
				最终结果为 "312"，这比 "123" 表示的数字更大 。 
				*/ 
                swap(strs[j], strs[j+1]);
            }
        }
    }
    
    string result;
    for (int i = 0; i < n; i++) {
        result += strs[i];
    }
    cout << result << endl;
    return 0;
}


/*
题解多数使用的sort自定义方法 
#include <bits/stdc++.h>
using namespace std;
int n;
string strs[21];

bool StringSort(string n,string m){
	return (n+m>m+n);
	//原理也是字典序的排序 
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>strs[i];
	}
	sort(strs+1,strs+n+1,StringSort);
	for(int i=1;i<=n;i++){
		cout<<strs[i];
	}
}
*/
