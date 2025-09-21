#include <bits/stdc++.h>

using namespace std;

#define N 4

int solveNQUtil(int board[N][N], int col); 

int isSafe(int row, int col, int board[N][N])
{
    int i,j;
    
    for(int j = 0;j<col;j++)
    {
        if(board[row][j] == 1)
            return 0;
    }
    
    for(int i = row,j = col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j] == 1)
            return 0;
    }
    for(int i = row,j = col;i<=N && j>=0;i++,j--)
    {
        if(board[i][j] == 1)
            return 0;
    }
    
    return 1;
}

void printSolution(int board[N][N])
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0; j<N;j++)
        {
            cout << " " << board[i][j] << " ";
        }
        cout<<"\n";
    }
}

int solveNQUtil(int board[N][N], int col) 
{
    if(col >= N)
    {
        return 1;
    }
    int row = 0;
    
    for(int i = 0;i<N;i++)
    {
        if(isSafe(i,col,board)==1)
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1)) 
                return 1;
            board[i][col] = 0; 
        }
    }
    
    return 0;
}

int main()
{
    int board[N][N];
    
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            board[i][j] = 0;
        }
    }
    
    if(solveNQUtil(board,0) == 0)
    {
        cout<< "No Solution exit";
        return 0;
    }
    printSolution(board);

    return 1;
}

