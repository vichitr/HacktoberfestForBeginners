#include <iostream>
using namespace std;

// Problem https://www.hackerrank.com/challenges/cpp-hello-world/problem
class HelloWorld
{public:
 void helloworld()
 {
     cout<<"Hello, World!";
 }
};
int main() {
    HelloWorld H;
    H.helloworld();
    
    return 0;
}
