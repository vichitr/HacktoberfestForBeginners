#include<bits/stdc++.h>
using namespace std;

class a{
    public:
    void display_a(){
        cout<<"from class a"<<endl;
    }
};
class b{
    public:
    void display_b(){
        cout<<"from class b"<<endl;
    }
};
class c:public a,public b{
    public:
    void display_c(){
        cout<<"from class c"<<endl;
    }
};
int main(){
    c x;
    x.display_a();
    x.display_b();
    x.display_c();
}