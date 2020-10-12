import os
import math


def get_info_file():
    temp_memory_board = []
    filename = "file-bot/board.txt"
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            memory_board = f.read().split('\n')
            for i in range(len(memory_board)):
                temp_row_memory = []
                for j in range(len(memory_board[i])):
                    temp_row_memory.append(memory_board[i][j])
                temp_memory_board.append(temp_row_memory)
    return temp_memory_board


def save_info_file(board, filename):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename, "w") as f:
        for i in range(len(board)):
            columns = "\n" if i > 0 else ""
            for j in range(len(board[i])):
                if board[i][j] == "b":
                    columns = columns + "-"
                else:
                    columns = columns + board[i][j]
            f.write(columns)


def update_info_file(board):
    filename = "file-bot/board.txt"
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            new_memory_board = []
            memory_board = f.read().split('\n')
            for i in range(len(memory_board)):
                new_row_memory = []
                for j in range(len(memory_board[i])):
                    if ((memory_board[i][j] == 'o' and board[i][j] == '-') or
                        (memory_board[i][j] == 'd' and board[i][j] == '-') or
                            (memory_board[i][j] == 'd' and board[i][j] == 'b')):
                        new_row_memory.append('-')
                    elif memory_board[i][j] == 'o' and board[i][j] == 'd':
                        new_row_memory.append('d')
                    else:
                        new_row_memory.append(memory_board[i][j])
                new_memory_board.append(new_row_memory)
            save_info_file(new_memory_board, filename)
    else:
        save_info_file(board, filename)


def update_position(posr, posc, dirties):
    nearest_dirt = []
    for i in range(len(dirties)):
        result = math.sqrt(
            ((dirties[i][0] - posr) ** 2) + ((dirties[i][1] - posc) ** 2))
        nearest_dirt.append(result)
    return [x for (y, x) in sorted(zip(nearest_dirt, dirties))]


def get_element_board(board, element):
    dirties = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] in element:
                dirties.append([i, j])
    return dirties


def next_move(posx, posy, board):
    update_info_file(board)
    elements = get_element_board(board, ['d'])
    if len(elements) == 0:
        elements = get_element_board(get_info_file(), ['o', 'd'])
    next_dirt = update_position(posx, posy, elements)
    if (len(next_dirt) > 0):
        if next_dirt[0][1] > posy:
            print('RIGHT')
        elif next_dirt[0][1] < posy:
            print('LEFT')
        elif next_dirt[0][0] < posx:
            print('UP')
        elif next_dirt[0][0] > posx:
            print('DOWN')
        else:
            print('CLEAN')


if __name__ == "__main__":
    pos = [int(i) for i in input().strip().split()]
    board = [[j for j in input().strip()] for i in range(5)]
    next_move(pos[0], pos[1], board)
