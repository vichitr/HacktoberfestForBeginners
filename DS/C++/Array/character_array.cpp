#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[100]="Apple";
    int i=0;
    while(a[i]!='\0'){
        cout<<a[i];
        i++;
    }
    int n;
    cin>>n;   
    cin.ignore(); 
    char b[n+1];    
    cin.getline(b,n);
    cin.ignore();
    cout<<b;
}
