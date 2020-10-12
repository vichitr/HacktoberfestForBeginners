def next_move(player, board):
    print("Player: {}".format(player))
    move = ''
    for i in range(len(board)):
        for j in range(len(board[i])):
            if i == 0 and j == 1 and board[i][j] == '-':
                move = 'UP'
            if i == 0 and j == 1 and board[i][j] == '-':
                move = 'RIGHT'
    print(move)


if __name__ == "__main__":
    player = int(input())
    board = [[j for j in input().strip()] for i in range(3)]
    next_move(player, board)
