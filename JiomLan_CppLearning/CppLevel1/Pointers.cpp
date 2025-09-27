#include <iostream>
using namespace std;

int main(){
    int a = 5;
    // &a -> 表示成地址 (取址符)
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    // *变量名 -> 指针变量 
    int *intpoint;
    intpoint = &a;

    cout << "Value of p: " << intpoint << endl;
    cout << "Value pointed by p: " << *intpoint << endl;
    cout << "Address of p: " << &intpoint << endl;

    int *ptr = NULL;
    cout << "Value of ptr: " << ptr << endl;

    return 0;
}
