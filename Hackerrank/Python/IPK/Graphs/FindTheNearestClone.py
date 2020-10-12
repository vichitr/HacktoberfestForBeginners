from collections import defaultdict, deque


def solve(n, g, color, color_to_analyze):
    queue = deque()
    length = [-1] * (n + 1)
    visited = [False] * (n + 1)

    for v in range(1, n + 1):
        if color[v] == color_to_analyze:
            length[v] = 0
            queue.appendleft(v)

    while queue:
        v = queue.pop()
        visited[v] = True

        for u in g[v]:
            if not visited[u]:
                if length[u] != -1:
                    return length[v] + length[u] + 1
                else:
                    length[u] = length[v] + 1
                    queue.appendleft(u)

    return -1


def main():
    n, m = map(int, input().split())
    g = defaultdict(set)

    for _ in range(m):
        u, v = map(int, input().split())
        g[u].add(v)
        g[v].add(u)

    color = [0] * (n + 1)
    color[1:] = list(map(int, input().split()))
    color_to_analyze = int(input())

    print(solve(n, g, color, color_to_analyze))


if __name__ == '__main__':
    main()
