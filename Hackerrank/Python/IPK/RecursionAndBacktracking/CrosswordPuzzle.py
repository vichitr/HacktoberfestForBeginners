N = 10


def field2str(field):
    return '\n'.join(map(''.join, field))


def solve(field, words, positions):
    if not words:
        print(field2str(field))
        exit()

    words, word = words[:-1], words[-1]

    for position in positions:
        i, j, di, dj = position
        go_further = True
        next_field = [row[:] for row in field]

        for letter in word:
            if (i > N - 1 or j > N - 1 or
                    (next_field[i][j] != '-' and next_field[i][j] != letter)):
                go_further = False
                break

            next_field[i][j] = letter
            i += di
            j += dj

        if i < N and j < N and next_field[i][j] == '-':
            go_further = False

        if go_further:
            next_positions = positions.copy()
            next_positions.remove(position)
            solve(next_field, words, next_positions)


def main():
    field = [list(input()) for _ in range(N)]
    words = input().split(';')

    positions = set()

    for i in range(N):
        for j in range(N):
            if field[i][j] == '-':
                if ((i == 0 or field[i - 1][j] != '-') and
                        (i == N - 1 or field[i + 1][j] == '-')):
                    positions.add((i, j, 1, 0))
                if ((j == 0 or field[i][j - 1] != '-') and
                        (j == N - 1 or field[i][j + 1] == '-')):
                    positions.add((i, j, 0, 1))

    solve(field, words, positions)


if __name__ == '__main__':
    main()
