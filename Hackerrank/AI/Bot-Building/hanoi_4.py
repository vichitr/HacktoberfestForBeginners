from collections import deque


def moves(x):
    for i in range(len(x)):
        if x[i]:
            for j in range(len(x)):
                if not x[j] or x[i][-1] < x[j][-1]:
                    yield (i, j)


def goal(x):
    return all([len(x[i]) == 0 for i in range(1, len(x))])


def bfs(x):
    def make_tuple(z):
        return tuple(tuple(t) for t in z)

    def do_move(g, m):
        y = [list(t) for t in g]
        y[m[1]].append(y[m[0]].pop())
        y[1:4] = sorted(y[1:4], key=lambda t: t[-1] if t else 0)
        return make_tuple(y)
    visited = set()
    start = (make_tuple(x), 0)
    q = deque([start])
    visited.add(start)
    while q:
        node, depth = q.popleft()
        if goal(node):
            return depth
        for move in moves(node):
            child = do_move(node, move)
            if child not in visited:
                visited.add(child)
                q.append((child, depth+1))


N = int(input())
A = [[] for i in range(4)]
R = [int(t) for t in input().split()]
for i in range(N):
    A[R[i]-1] = [(i+1)] + A[R[i]-1]
print(bfs(A))
