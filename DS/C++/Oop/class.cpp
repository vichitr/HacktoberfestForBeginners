#include<bits/stdc++.h>
using namespace std;

class student{
    string name;
    int roll;
    char gender;
    public:
    void set_name(string s){
        name=s;
    }
    void set_roll(int r){
        roll=r;
    }
    void set_gender(char g){
        gender=g;
    }
    void get_data(){
        cout<<"Name "<<name<<" Roll "<<roll<<" Gender "<<gender;
    }
};

int main(){
    student a[3];
    string name;
    int r;
    char g;
    for(int i=0;i<3;i++){
        cin>>name;
        a[i].set_name(name);
        cin>>r;
        cin>>g;
        a[i].set_roll(r);
        a[i].set_gender(g);
    }
    for(int i=0;i<3;i++){
        a[i].get_data();
        cout<<endl;
    }
}