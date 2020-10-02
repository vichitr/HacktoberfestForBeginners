
nm = input().split()

n = int(nm[0])

m = int(nm[1])

arr = []

for _ in range(n):
    arr.append(list(map(int, input().rstrip().split())))

k = int(input())
arr = sorted(arr, key = lambda athlete: athlete[k])
for i in arr:
    print(*i)

