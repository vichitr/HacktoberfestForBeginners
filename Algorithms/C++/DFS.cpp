
// DFS and graph implementaion using stl c++
#include<iostream>
#include<vector>
using namespace std;
 void addEdge(vector<int> arr[],int a,int b);
 void addEdge(vector<int> arr[],int a,int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
}
void DFSuntil(int i,vector<int> arr[],vector<bool> &visited)
{
    cout<<i<<" ";
    visited[i]=true;
    for(int k=0;k<arr[i].size();k++)
    {
        if(visited[arr[i][k]]==false)
        DFSuntil(arr[i][k],arr,visited);
    }
}
void DFS(vector<int> arr[],int n)
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        DFSuntil(i,arr,visited);
    }
}

int main()
{
    int n;
    cin>>n;
    int edge;
    vector<int> arr[n];
    cin>>edge;int a;int b;
    for(int i=0;i<edge;i++)
    {
        cin>>a;
        cin>>b;
       addEdge(arr,a,b);
    }
    vector<int>::iterator itr;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(itr=arr[i].begin();itr<arr[i].end();itr++)
        {
            cout<<*itr<<" ";
        }
        cout<<endl;
    }
    
    
    DFS(arr,n);
    
    
    return 0;
}
