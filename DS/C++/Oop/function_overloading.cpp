#include<bits/stdc++.h>
using namespace std;

class addition{
    public:
    void add(int a,int b){
        cout<<a+b<<endl;
    }
    void add(int a,int b,int c){
        cout<<a+b+c<<endl;
    }
    void add (int a,int b,int c,int d){
        cout<<a+b+c+d<<endl;
    }
};
int main(){
    addition a;
    a.add(3,2);
    a.add(5,4,2);
    a.add(6,4,3,2);
}