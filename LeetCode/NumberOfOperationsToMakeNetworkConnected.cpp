/*Difficulty Level :- Medium
Problem Description:-
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between 
computers a and b. Any computer can reach any other computer directly or indirectly through the network.
Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected 
computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible,
return -1. 
*/
class Solution {
public:
    void dfs(set<int> adj[], int& e, unordered_set<int>& s, int v)
    {
        if(s.find(v)!=s.end()) return;
        s.insert(v);
        for(auto& i:adj[v])
        {
            if(s.find(i) == s.end())
            {
                e++;
                dfs(adj, e, s, i);
            }
            
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        //find no. of extra edges and no. of disconnected components-1, if both are equal return no. of extra edges
        //else return -1
        //convert edge list to adj list
        set<int> adj[n];
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].insert(connections[i][1]);
            adj[connections[i][1]].insert(connections[i][0]);
        }
        int count=0; //no. of connected components
        int e=0; //counts no. of edges used
        unordered_set<int> s;
        
        //dfs to find connected components
        for(int i=0; i<n; i++)
        {
            if(s.find(i)==s.end())
            {
                count++;
                dfs(adj, e, s, i);
            }
        }
        if(count-1 <= connections.size()- e)
            return count-1;
        else return -1;
    }
};
