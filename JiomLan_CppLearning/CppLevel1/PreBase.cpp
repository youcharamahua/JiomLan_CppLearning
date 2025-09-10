#include <iostream> 
// 所谓iostream 就是 input output stream 
// 你问我这个双斜线是什么？这个是注释符号！注释符号后面的内容机器不会编译
using namespace std;

int main(){
    // io speed up
    const char endl = '\n';
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << "Hello World!";
    return 0;
}