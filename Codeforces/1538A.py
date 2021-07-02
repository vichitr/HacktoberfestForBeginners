#FazleRabbiFerdaus

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))

    mx, mn = l.index(max(l)), l.index(min(l))
    mx_r, mn_r = l[::-1].index(max(l)), l[::-1].index(min(l))
    if max(mx, mn) < max(mx_r, mn_r):
        st = max(mx, mn)
    else:
        st = max(mx_r, mn_r)

    n_st = 0
    if mx < mx_r:
        n_st += mx+1
    else:
        n_st += mx_r+1

    if mn < mn_r:
        n_st += mn+1
    else:
        n_st += mn_r+1
    #print(st, n_st)
    print(min(st+1, n_st))
