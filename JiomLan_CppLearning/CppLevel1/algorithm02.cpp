//P4414 [COCI 2006/2007 #2] ABC
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int nums[3];
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums, nums + 3);
    int a = nums[0], b = nums[1], c = nums[2];
    
    string order;
    cin >> order;
    
    for (int i = 0; i < 3; i++) {
        if (order[i] == 'A') {
            cout << a;
        } else if (order[i] == 'B') {
            cout << b;
        } else if (order[i] == 'C') {
            cout << c;
        }
        if (i < 2) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}