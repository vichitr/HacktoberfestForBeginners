from itertools import product

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
print(*product(A, B))
