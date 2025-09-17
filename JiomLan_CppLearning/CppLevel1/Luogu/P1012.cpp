//#include <iostream>
//#include <string>
//����ʹ������ͷ�ļ� 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string strs[21];
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    //�ַ�����������char���͵�����
	/*
	�ֵ���Lexicographical Order����һ�ֻ�����ĸ���ַ�˳�������ʽ�� 
	1.�������ַ����ĵ�һ���ַ���ʼ�Ƚ�
	2.����ַ���ͬ��������Ƚ���һ���ַ�
	3.���������ͬ���ַ���������������ַ��ı���ֵ���� ASCII �룩����˳��
	4.���һ���ַ�������һ���ַ�����ǰ׺����϶̵��ַ�������ǰ��
	*/
	
	
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strs[j] + strs[j+1] < strs[j+1] + strs[j]) {
            	//�����ֵ���ıȽ�
				/*
				���� �Ƚ����� "12" �� "3"
				�������������������� 
				"12" + "3" = "123"
				"3" + "12" = "312"
				�������������������� 
				��һ���ַ���'1' �� '3'��'3' �� ASCII ����� 
				��� "312" ���ֵ������ "123"�� 
				���� "3" Ӧ������ "12" ǰ�棬 
				���ս��Ϊ "312"����� "123" ��ʾ�����ָ��� �� 
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
������ʹ�õ�sort�Զ��巽�� 
#include <bits/stdc++.h>
using namespace std;
int n;
string strs[21];

bool StringSort(string n,string m){
	return (n+m>m+n);
	//ԭ��Ҳ���ֵ�������� 
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
