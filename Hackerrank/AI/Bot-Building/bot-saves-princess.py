# Princess Peach is trapped in one of the four corners of a square grid. 
# You are in the center of the grid and can move one step at a time in 
# any of the four directions. Can you rescue the princess?

# Complete the function displayPathtoPrincess which takes in two 
# parameters - the integer N and the character array grid. The grid 
# will be formatted exactly as you see it in the input, so for the 
# sample input the princess is at grid[2][0]. The function shall output 
# moves (LEFT, RIGHT, UP or DOWN) on consecutive lines to rescue/reach 
# the princess. The goal is to reach the princess in as few moves as possible.

# Link: https://www.hackerrank.com/challenges/saveprincess
# Developer: Murillo Grubler

def displayPathtoPrincess(n,grid):
    pos_col = {}
    pos_row = {}
    not_find = True

    for i in range(n):
        line = len(grid[i])
        for j in range(line):
            if grid[i][j] == 'm':
                pos_row['m'] = i
                pos_col['m'] = j
            elif grid[i][j] == 'p':
                pos_row['p'] = i
                pos_col['p'] = j

    while (not_find):
        if pos_row['m'] < pos_row['p']:
            pos_row['m'] = pos_row['m'] + 1
            print ('DOWN')
        elif pos_row['m'] > pos_row['p']:
            pos_row['m'] = pos_row['m'] - 1
            print ('UP')

        if pos_col['m'] < pos_col['p']:
            pos_col['m'] = pos_col['m'] + 1
            print ('RIGHT')
        elif pos_col['m'] > pos_col['p']:
            pos_col['m'] = pos_col['m'] - 1
            print ('LEFT')
        
        if pos_col['m'] == pos_col['p'] and pos_row['m'] == pos_row['m']:
            not_find = False

#print all the moves here
m = int(input())
grid = [] 
for i in range(0, m): 
    grid.append(input().strip())

displayPathtoPrincess(m,grid)