from itertools import combinations_with_replacement

line = input().split()
string, k = sorted(line[0]), int(line[1])

combs = list(combinations_with_replacement(string, k))
combs = [''.join(tup) for tup in combs]
print(*combs, sep='\n')
