from itertools import combinations

line = input().split()
string, k = sorted(line[0]), int(line[1])

for r in range(1, k + 1):
    combs = list(combinations(string, r))
    combs = [''.join(tup) for tup in combs]
    print(*combs, sep='\n')
