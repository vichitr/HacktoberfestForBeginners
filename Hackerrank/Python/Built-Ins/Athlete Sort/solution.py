n, m = (int(x) for x in input().split())

athletes = []
for _ in range(n):
    athletes.append([int(x) for x in input().split()])

k = int(input())
athletes.sort(key=lambda athlete: athlete[k])

for athlete in athletes:
    print(*athlete)
