#include<bits/stdc++.h>
using namespace std;

int isperfect(int num){
    int sum=1;
    for(int i=2;i<sqrt(num);i++){
        if(num%i==0){
            if(i==num/i)
            sum+=i;
            else
            sum+=i + num/i;
        }
    
    }
    if(sum==num)
    return 1;
    return 0;
}

int maxperfect(int a[],int n,int k){    
    int sum=0,msum=0;
    for(int i=0;i<n;i++){
        if(isperfect(a[i]))
        a[i]=1;
        else
        a[i]=0;
    }
    for(int i=0;i<k;i++){
        sum=sum+a[i];
    }
    msum=sum;
    for(int i=k;i<n;i++){
        sum=sum +a[i]-a[i-k];
        msum=max(sum,msum);
    }
    return msum;
}
int main(){
    int a[]={28,2,3,6,496,99,8128,24};
    int n=8;
    int k=4;
    cout<<maxperfect(a,n,k);
}