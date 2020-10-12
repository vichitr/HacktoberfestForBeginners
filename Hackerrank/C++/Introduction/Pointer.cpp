#include <iostream>
using namespace std ; 
void fun1(int *a,int *b) {
  cout << *a+*b  << endl  ; 
  cout <<  abs(*a-*b) << endl  ; 
}

int main() {
    int a, b;
    cin >> a ; 
    cin >> b ; 
    int *pa = &a, *pb = &b;  
fun1(pa , pb ) ; 
    return 0;
}
