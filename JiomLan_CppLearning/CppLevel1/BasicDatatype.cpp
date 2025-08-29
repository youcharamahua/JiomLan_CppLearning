#include <iostream>
using namespace std;

int main() {
	short a = 10; //2byte [-(2^15),(2^15)-1] 0000 0000 0000 0000
	int b = 20; //4byte 
	long c = 30; //4byte
	long long d = 40; //8byte

	float e = 3.14f; //4byte
	double f = 3.14159; //8byte

	char g = 'A'; //1byte

	bool h = true; //1byte (true(1) or false(0))

	cout << "Hello, World!" << endl;
	system("pause");
	return 0;
}