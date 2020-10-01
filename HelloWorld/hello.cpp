#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" ;
    cout<< endl;
    int a,r,n;
    n=687;
    while(n!=0)
    {
        a=n%10;
        r=r+a*10;
        n=n/10;
    }
    return 0;
}
