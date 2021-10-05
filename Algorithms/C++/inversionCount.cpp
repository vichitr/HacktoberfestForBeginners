//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

    int merge(vector<int>& arr,int l,int mid,int r){
        int temp[r-l+1];
        int i=l,j=mid+1,k=0,inv=0;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
            }
            else{
                temp[k]=arr[j];
                inv+=mid+1-i;
                j++;
            }
            k++;
        }
        while(i<=mid){
            temp[k]=arr[i];
            i++;
            k++;
        }
        while(j<=r){
            temp[k]=arr[j];
            j++;
            k++;
        }
        for(int p=l;p<=r;p++){
            arr[p]=temp[p-l];
        }
        return inv;
    }


  int mergeSort(vector<int>& arr,int l,int r){
        int inv=0;
        if(l<r){
            int mid=l+(r-l)/2;
            inv+=mergeSort(arr,l,mid);
            inv+=mergeSort(arr,mid+1,r);
            inv+=merge(arr,l,mid,r);
        }
        return inv;
    }




int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jets();
    int n;
    cin>>n;
    std::vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Inversions in array are: "<<mergeSort(arr,0,n-1);


    return 0;
}