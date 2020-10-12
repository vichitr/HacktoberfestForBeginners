# Complete the function nextMove which takes in 4 parameters - an 
# integer N, integers r and c indicating the row & column position 
# of the bot and the character array grid - and outputs the next 
# move the bot makes to rescue the princess.

# Link: https://www.hackerrank.com/challenges/saveprincess2
# Developer: Murillo Grubler

def nextMove(n,r,c,grid):
    pos_col_m = c
    pos_row_m = r
    pos_col_p = pos_row_p = 0

    for i in range(n):
        line = len(grid[i])
        for j in range(line):
            if grid[i][j] == 'p':
                pos_row_p = i
                pos_col_p = j

    # Verify the positions of the bot with the princess
    if pos_row_m < pos_row_p:
        pos_row_m = pos_row_m + 1
        return 'DOWN'
    elif pos_row_m > pos_row_p:
        pos_row_m = pos_row_m - 1
        return 'UP'

    if pos_col_m < pos_col_p:
        pos_col_m = pos_col_m + 1
        return 'RIGHT'
    elif pos_col_m > pos_col_p:
        pos_col_m = pos_col_m - 1
        return 'LEFT'
        
# Set the data
n = int(input())
r,c = [int(i) for i in input().strip().split()]
grid = []
for i in range(0, n):
    grid.append(input())

# print the first move here
print(nextMove(n,r,c,grid))
