
from collections import defaultdict

import heapq


def dijkstra(S, N, G):
    D    = {}
    H    = [(0, S)]

    for n in range(1, N + 1):
        D[n] = float('inf')

    D[S] = 0

    while H:
        t = heapq.heappop(H)
        for h in G[t[1]]:
            if D[h[0]] > D[t[1]] + h[1]:
                D[h[0]] = D[t[1]] + h[1]
                if (h[1], h[0]) in H:
                    H.remove((h[1], h[0]))
                    heapq.heapify(H)
                heapq.heappush(H, (D[h[0]], h[0]))

    return D


def main():
    T = int(input())

    for _ in range(T):
        N, M = [int(i) for i in input().split()]

        G    = defaultdict(set)

        for _ in range(M):
            e = [int(i) for i in input().split()]
            G[e[0]].add((e[1], e[2]))
            G[e[1]].add((e[0], e[2]))

        S    = int(input())

        D    = dijkstra(S, N, G)
        print(' '.join(str(D[n]) if D[n] != float('inf') else '-1' for n in range(1, N + 1) if n != S))


if __name__ == "__main__":
    main()
