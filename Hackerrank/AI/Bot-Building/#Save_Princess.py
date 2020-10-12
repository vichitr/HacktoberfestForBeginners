def displayPathtoPrincess(n, grid):
    g = Grid(n, grid)
    if not g.is_valid():
        raise Exception('Grid validation error: %s' % '\n'.join(g.errors))
    g.get_bot_coordinates()
    g.get_princess_coordinates()
    print(g.get_path())


class Grid(object):
    def __init__(self, n, grid):
        self.n = n
        self.matrix = grid
        self.errors = []
        self.princess_marker = 'p'
        self.bot_marker = 'm'
        self.princess_coord = None
        self.bot_coord = None

    def has_valid_row_count(self):
        return self.n == len(self.matrix)

    def has_valid_column_count(self):
        for i in self.matrix:
            if not len(i) == self.n:
                self.errors.append(
                    'Grid expected column size %s but got %s' % (self.n, len(i)))
                return False
        return True

    def is_valid(self):
        r = True
        if not self.has_valid_row_count():
            self.errors.append('Grid expected row size %s but got %s' % (
                self.n, len(self.matrix)))
            r = False
        if not self.has_valid_column_count():
            r = False
        return r

    def get_coordinates_for(self, val):
        for x, row in enumerate(self.matrix):
            for y, col in enumerate(row):
                if col == val:
                    return (x, y)

    def get_princess_coordinates(self):
        if not self.princess_coord:
            self.princess_coord = self.get_coordinates_for(
                self.princess_marker)
        return self.princess_coord

    def get_bot_coordinates(self):
        if not self.bot_coord:
            self.bot_coord = self.get_coordinates_for(self.bot_marker)
        return self.bot_coord

    def get_path(self):
        path = []
        row_diff = self.bot_coord[0] - self.princess_coord[0]
        col_diff = self.bot_coord[1] - self.princess_coord[1]
        if row_diff > 0:
            row_direction = 'UP'
        else:
            row_direction = 'DOWN'
        if col_diff > 0:
            col_direction = 'LEFT'
        else:
            col_direction = 'RIGHT'
        for i in range(abs(row_diff)):
            path.append(row_direction)
        for i in range(abs(col_diff)):
            path.append(col_direction)
        return '\n'.join(path)


m = eval(input())
grid = []
for i in range(0, m):
    grid.append(input().strip())
displayPathtoPrincess(m, grid)
