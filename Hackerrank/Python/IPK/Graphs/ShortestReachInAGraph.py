from collections import defaultdict, deque


def solve(n, g, start):
    length = [-1] * (n + 1)

    queue = deque()
    queue.appendleft(start)
    length[start] = 0

    while queue:
        v = queue.pop()

        for u in g[v]:
            if length[u] == -1:
                length[u] = length[v] + 6
                queue.appendleft(u)

    return length[1:start] + length[start + 1:]


def main():
    qs = int(input())

    for _ in range(qs):
        n, m = map(int, input().split())

        g = defaultdict(set)
        for _ in range(m):
            u, v = map(int, input().split())
            g[u].add(v)
            g[v].add(u)

        start = int(input())
        answer = solve(n, g, start)
        print(' '.join(map(str, answer)))


if __name__ == '__main__':
    main()
