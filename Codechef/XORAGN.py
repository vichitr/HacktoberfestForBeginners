'''
Author: Juan Pablo Yamamoto
Problem: XOR Again | XORAGN
'''

t = [int(x) for x in input().split(" ")]

b = [x+y for x in t for y in t]

z = 0

for x in b:
    z ^= x

print(z)

