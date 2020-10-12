class Grid:
    def __init__(self, n, m, cells):
        self.n = n
        self.m = m
        self.cells = cells
        self.visited = [[False] * m for _ in range(n)]

    def __getitem__(self, v):
        return self.cells[v[0]][v[1]]

    def visit(self, v):
        self.visited[v[0]][v[1]] = True

    def is_visited(self, v):
        return self.visited[v[0]][v[1]]

    def neighbours(self, v):
        return [(x, y)
                for x in range(max(0, v[0] - 1), min(v[0] + 2, self.n))
                for y in range(max(0, v[1] - 1), min(v[1] + 2, self.m))
                if not (x == v[0] and y == v[1])]


def count(grid, v):
    result = 1
    grid.visit(v)

    for u in grid.neighbours(v):
        if grid[u] == 1 and not grid.is_visited(u):
            result += count(grid, u)

    return result


def main():
    n = int(input())
    m = int(input())
    cells = [list(map(int, input().split())) for _ in range(n)]
    grid = Grid(n, m, cells)
    answer = 0

    for v in [(x, y) for x in range(n) for y in range(m)]:
        if grid[v] == 1 and not grid.is_visited(v):
            answer = max(answer, count(grid, v))

    print(answer)


if __name__ == '__main__':
    main()
