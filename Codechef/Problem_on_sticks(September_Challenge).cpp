#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T,i;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        int count=0;
        for(i=0;i<n;i++){
            if(arr[i]==0)
                continue;
            if(arr[i+1]==arr[i])
                count+=0;
            else
                count+=1;
        }
        cout<<count<<endl;
    }
    return 0;
}
