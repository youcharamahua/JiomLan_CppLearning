#include <iostream>
using namespace std;

int main() {
	short a = 10; //2byte [(2^15),(2^15)-1]
	int b = 20; //4byte 
	long c = 30; //4byte
	long long d = 40; //8byte

	float e = 3.14f; //4byte(С�����6~7λ)
	double f = 3.14159; //8byte��С�����15~16λ��

	char g = 'A'; //1byte

	bool h = true; //1byte (true(1) or false(0))

	cout << "Hello, World!" << endl;
	system("pause");
	return 0;
}