    class T:
        h = ('Lose', 'Loop', 'Win')
        def __init__(t):
            t.s = list(map(int, input().split()))[1:]
            t.p = [len(t.s)] * n
            t.p[0] = 0
        def f(t, i):
            for d in t.s:
                j = (i - d) % n
                if t.p[j] > 0: yield j
        def g(t):
            print(*[t.h[min(q, 1)] for q in t.p[1:]])
    n = int(input())
    r, m = T(), T()
    q = [(r, m, 0), (m, r, 0)]
    while q:
        x, y, i = q.pop()
        for j in y.f(i):
            y.p[j] = -1
            for k in x.f(j):
                x.p[k] -= 1
                if not x.p[k]: q.append((x, y, k))
    r.g()
    m.g()