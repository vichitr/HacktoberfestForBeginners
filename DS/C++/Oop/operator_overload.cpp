#include<bits/stdc++.h>
using namespace std;

class overload{
    public:
    string name;
    int age;
    overload(string s,int age){
        name=s;
        age=age;
    }
    bool operator ==(overload b){
        return (name==b.name) && (age=b.age);
    }
};

int main(){
    overload a("NK",22);
    overload b("NK",22);
    if(a==b){
        cout<<"both object are equal";
    }
    else
    cout<<"both object are not equal";
}