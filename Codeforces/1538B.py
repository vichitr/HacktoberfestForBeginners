#fazlerabbiferdaus

for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    if sum(l) // n == sum(l) / n:
        count = 0
        mx = sum(l) // n
        for i in l:
            if i > mx:
                count += 1
        print(count)
    else:
        print(-1)
