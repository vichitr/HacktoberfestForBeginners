#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int v[],int W,int n){
    if(n==0 || W==0)
    return 0;
    if(wt[n-1]>W)
    {
        return knapsack(wt,v,W,n-1);
    }
    return max(knapsack(wt,v,W-wt[n-1],n-1) +v[n-1],knapsack(wt,v,W,n-1));


}
int main(){
    int wt[]={10,20,30};
    int v[]={100,50,150};
    int W=50;
    cout<<knapsack(wt,v,W,3);
}