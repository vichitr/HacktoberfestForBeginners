//vipul sharma, code forces global round question 1
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    int orig[n];
    float temp;
    int sum = 0;
    for(int i =0; i<n; i++){
        cin>>temp;
        orig[n] = temp;
        if((int)temp%2==0){
            a[i] = temp/2;
        }
        else{
            temp = temp/2.0;
            temp += 0.5;
            a[i] = (int)temp;
        }
        sum+=a[i];
    }
    int change=1;
    if(sum>0){
        for(int i =0; i<n; i++){
            if(sum!=0 && orig[i]%2!=0 && a[i]<0){
                a[i] -=1; 
                sum -=1;
            }
            else if(sum!= 0 && orig[i]%2!=0 && a[i]>0){
                a[i] -=1;
                sum -=1;
            }
            cout<<a[i]<<'\n';
        }
    }
    else if(sum<0){ //this condition will never arise as by taking ceil we ensure sum>0
        for(int i =0; i<n; i++){
            //if(sum!=0 && orig[i]%2!=0 && a[i]<0){
            //    a[i] +=1;   //wrong already taken ceil this will add 1 to ceil
            //    sum +=1;
            //}
            //if(sum!= 0 && orig[i]%2!=0 && a[i]>0){
            //    a[i] +=1;     //adding 1 to ceil is wrong
            //    sum +=1;
            //}
            cout<<a[i]<<'\n';
        }
    }
    else{
        for(int i = 0;i<n; i++){
            cout<<a[i]<<'\n';
        }
    }
    return 0;
}