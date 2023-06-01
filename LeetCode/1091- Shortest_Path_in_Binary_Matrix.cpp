// This is solution of Leetcode Problem : 1091. Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
// I have used BFS traversal approach here 
// Time and Space Complexity both are O(n^2) here

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]) return -1;
        queue<pair<int , int>> q;
        vector<vector<bool>>seen(n , vector<bool>(n,false ));
        seen[0][0] = true;
        q.push({0 , 0});
       
        while(!q.empty()){
            auto a=q.front(); q.pop();
            int i=a.first , j=a.second;
            if(i==n-1 && j==n-1){
                return grid[i][j] + 1;
            }
            int I[] = {0 , 0 , 1 , 1 , 1, -1 , -1 , -1};
            int J[] = {1 , -1, 0 , -1, 1 , 0 , -1 , 1 };
            for(int p=0 ; p<8 ; p++){
                int x = i + I[p];
                int y = j + J[p];
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==0 && !seen[x][y]){
                grid[x][y] =1+grid[i][j]; 
                seen[x][y] = true;
                q.push({x, y});
                }
            }
        }
        return -1;
    }
};