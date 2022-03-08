#include<bits/stdc++.h>
using namespace std;

class a{
    void display(){
        cout<<"this is private method of a"<<endl;
    }
    public:
    void display_a(){
        cout<<"this is public method of a"<<endl;
    }
};
class b:public a {
    void display(){
        cout<<"this is private  ethod of b"<<endl;
    }
    public:
    void display_b(){
        cout<<"this is public method of b"<<endl;
    }
};
int main(){
    a x;
    b y;
    x.display_a();
    y.display_a();
    y.display_b();
}