"""
Funny that this challenge says it's only for Python 2,
as if Python 3 doesn't have an eval() function.
"""

x, k = (int(a) for a in input().split())
P = input()
print(eval(P) == k)