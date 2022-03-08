#include<bits/stdc++.h>
using namespace std;

int kadane(int a[],int n){
    int current_sum=0,mxsum=INT_MIN;
    for(int i=0;i<n;i++){
        current_sum+=a[i];
        if(current_sum<0)
            current_sum=0;
        mxsum=max(current_sum,mxsum);    
    }
    return mxsum;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int unwraped_mxsum=kadane(a,n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        a[i]=-a[i];
    }
    int wraped_mxsum=sum + kadane(a,n);
    cout<<max(wraped_mxsum,unwraped_mxsum);

}