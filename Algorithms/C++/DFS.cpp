#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int a,int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
void dfs(vector<int> graph[],int start)
{
    stack<int> st;
    vector<bool> visited(graph->size(),false);
    st.push(start);
    visited[start] = true;
    while(!st.empty())
    {
        int v = st.top();
        cout<<v<<" ";
        st.pop();
        for(vector<int>::iterator it = graph[v].begin();it!=graph[v].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                st.push(*it);
            }
        }
    }

}


int main()
{
    int V = 7;
    vector<int> graph[V];
    // Values for the graph formation
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,5);
    addEdge(graph,2,6);
    addEdge(graph,3,5);
    addEdge(graph,4,3);
    addEdge(graph,5,2);
    addEdge(graph,5,3);
    cout<<"The output of DFS is\n";
    dfs(graph,0);
    
}