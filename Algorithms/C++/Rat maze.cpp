#include <bits/stdc++.h>

using namespace std;

#define N 4

int solveKTUtil(int maze[N][N], int x, int y, int sol[N][N]); 

int isSafe(int x, int y, int maze[N][N])
{
    if(x >=0 && x<N && y>=0 && y<N && maze[x][y] == 1) return 1;
    return 0;
}

void printSolution(int sol[N][N])
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0; j<N;j++)
        {
            cout << " " << sol[i][j] << " ";
        }
        cout<<"\n";
    }
}

int solveKTUtil(int maze[N][N], int x, int y, int sol[N][N]) 
{
    if(x == N-1 && y == N-1 && maze[N-1][N-1] == 1)
    {
        sol[x][y] = 1;
        return 1;
    }
    
    if(isSafe(x,y,maze)==1)
    {
        sol[x][y] = 1;
        
        if (solveKTUtil(maze, x + 1, y, sol)==1) 
            return 1;
        if (solveKTUtil(maze, x, y + 1, sol)==1) 
            return 1;
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

int main()
{
     int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 1, 1 }, 
                       { 0, 0, 1, 0 }, 
                       { 1, 1, 1, 1 } };
                       
    int sol[N][N];
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            sol[i][j] = 0;
        }
    }
    
    // sol[0][0] = 1;
    
    if(solveKTUtil(maze,0,0,sol) == 0)
    {
        cout<< "No Solution exit";
        return 0;
    }
    printSolution(sol);

    return 1;
}

