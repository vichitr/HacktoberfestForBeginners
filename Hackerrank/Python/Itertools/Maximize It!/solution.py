from itertools import product

K, M = [int(x) for x in input().split()]
lists = [[int(x) for x in input().split()[1:]] for _ in range(K)]
cartesian_product = product(*lists)
results = map(lambda tup: sum(x**2 for x in tup) % M, cartesian_product)
print(max(results))
