from itertools import permutations

line = input().split()
string, r = sorted(line[0]), int(line[1])

perms = list(permutations(string, r))
perms = [''.join(tup) for tup in perms]
print(*perms, sep='\n')
