def nextMove(posr, posc, board):
    dirty_row = dirty_col = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 'd':
                dirty_row = i
                dirty_col = j
    if dirty_col < posc:
        print('LEFT')
    elif dirty_col > posc:
        print('RIGHT')
    elif dirty_row < posr:
        print('UP')
    elif dirty_row > posr:
        print('DOWN')
    else:
        print('CLEAN')


if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    nextMove(pos[0], pos[1], board)
