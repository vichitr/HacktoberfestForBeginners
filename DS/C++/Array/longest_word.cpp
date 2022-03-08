#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char s[n+1];
    cin.getline(s,n);
    cin.ignore();
    int i=0,mlen=0,len=0,pos;
    while(1){
        if(s[i]==' ' || s[i]=='\0'){                
            if(len>mlen){
                mlen=len;
                pos=i-len;
            }
            len=0;
        }
        else
        len++;

        if(s[i]=='\0')
        break;
        i++;
    }
    for(int j=0;j<mlen;j++){
        cout<<s[j+pos];
    }
}