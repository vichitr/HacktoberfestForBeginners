from collections import namedtuple

Edge = namedtuple('Edge', ['x', 'y', 'time'])


class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.size = [1] * (n + 1)
        self.has_machine = [False] * (n + 1)

    def join(self, x, y):
        px = self.root(x)
        py = self.root(y)

        if px != py:
            if self.has_machine[px] and self.has_machine[py]:
                return False
            if self.size[px] > self.size[py]:
                self.parent[py] = self.parent[px]
                self.size[px] += self.size[py]
                self.has_machine[px] |= self.has_machine[py]
            else:
                self.parent[px] = self.parent[py]
                self.size[py] += self.size[px]
                self.has_machine[py] |= self.has_machine[px]

        return True

    def root(self, x):
        while self.parent[x] != x:
            x = self.parent[x]
        return x


def main():
    n, k = map(int, input().split())
    edges = sorted([Edge(*map(int, input().split())) for _ in range(n - 1)],
                   key=lambda e: e.time, reverse=True)

    ds = DisjointSet(n)
    for _ in range(k):
        v = int(input())
        ds.has_machine[v] = True

    answer = 0
    for edge in edges:
        joined = ds.join(edge.x, edge.y)
        if not joined:
            answer += edge.time

    print(answer)


if __name__ == '__main__':
    main()
