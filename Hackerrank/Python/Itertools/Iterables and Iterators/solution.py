from itertools import combinations

_ = int(input())
letters = input().split()
k = int(input())

count = 0
combs = list(combinations(letters, k))
for tup in combs:
    if 'a' in tup:
        count += 1
print(count / len(combs))
