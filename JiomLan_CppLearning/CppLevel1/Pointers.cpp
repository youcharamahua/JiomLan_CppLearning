#include <iostream>
using namespace std;

int main(){
    int a = 5;
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    int *intpoint;
    intpoint = &a;

    cout << "Value of p: " << intpoint << endl;
    cout << "Value pointed by p: " << *intpoint << endl;

    int *ptr = NULL;
    cout << "Value of ptr: " << ptr << endl;

    return 0;
}
