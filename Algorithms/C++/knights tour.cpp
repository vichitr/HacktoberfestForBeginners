#include <bits/stdc++.h>

using namespace std;

#define N 8

int solveKTUtil(int xi, int yi, int move, int sol[N][N], int x[], int y[]); 

int isSafe(int xi, int yi, int sol[N][N])
{
    return (xi >=0 && xi<N && yi>=0 && yi<N && sol[xi][yi] == -1);
}

void printSolution(int sol[N][N])
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0; j<N;j++)
        {
            cout << " " << setw(2) << sol[i][j] << " ";
        }
        cout<<"\n";
    }
}

int solveKTUtil(int xi, int yi, int move, int sol[N][N], int x[], int y[]) 
{
    int k, next_x, next_y;
    if(move == N*N)
        return 1;
    
    for(k = 0;k<N;k++)
    {
        next_x = xi + x[k];
        next_y = yi + y[k];
        
        if(isSafe(next_x,next_y,sol))
        {
            sol[next_x][next_y] = move;
            if(solveKTUtil(next_x, next_y, move+1, sol, x, y)==1)
            {
                return 1;
            }
            else
            {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

int main()
{
    int sol[N][N];
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            sol[i][j] = -1;
        }
    }
    
    int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    
    sol[0][0] = 0;
    
    if(solveKTUtil(0, 0, 1, sol, x, y) == 0)
    {
        cout<< "No Solution exit";
        return 0;
    }
    else
    {
        printSolution(sol);
    }

    return 0;
}

