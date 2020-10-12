N = 10 ** 9


class DisjointSet:
    def __init__(self):
        self.parent = {}
        self.size = {}

    def join(self, x, y):
        self.parent[x] = self.parent.get(x, x)
        self.parent[y] = self.parent.get(y, y)
        self.size[x] = self.size.get(x, 1)
        self.size[y] = self.size.get(y, 1)
        px = self.root(x)
        py = self.root(y)

        if px != py:
            if self.size[px] > self.size[py]:
                self.parent[py] = self.parent[px]
                self.size[px] += self.size[py]
            else:
                self.parent[px] = self.parent[py]
                self.size[py] += self.size[px]

        return max(self.size[px], self.size[py])

    def root(self, x):
        while self.parent[x] != x:
            x = self.parent[x]
        return x


def main():
    qs = int(input())
    ds = DisjointSet()
    max_size = 0

    for _ in range(qs):
        x, y = map(int, input().split())
        size = ds.join(x, y)
        max_size = max(max_size, size)
        print(max_size)


if __name__ == '__main__':
    main()
