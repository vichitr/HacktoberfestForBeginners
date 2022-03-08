#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string name;
    int roll;
    char gender;
    student(){
        cout<<"default constructor"<<endl;
    }
    student(string s,int r,char g){
        name=s;
        roll=r;
        gender=g;
    }
    student(student &a){
        name=a.name;
        roll=a.roll;
        gender=a.gender;
    }
    
    void get_data(){
        cout<<"Name "<<name<<" Roll "<<roll<<" Gender "<<gender<<endl;
    }
};
int main(){
    student a;
    student b("Nk",1,'m');
    student c=b;
    b.get_data();
    c.get_data();
}