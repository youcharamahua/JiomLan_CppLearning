#include <iostream>
using namespace std;

namespace Fruits{
    string Apple = "Apple";
    string Banana = "Banana";
}

namespace Animals{
    string Dog = "Dog";
    string Cat = "Cat";
}

int main(){
    cout << Fruits::Apple << endl;
    cout << Fruits::Banana << endl;
    cout << Animals::Dog << endl;
    cout << Animals::Cat << endl;

    return 0;
}