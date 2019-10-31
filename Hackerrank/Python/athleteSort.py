# URL: https://www.hackerrank.com/challenges/python-sort-sort/

from __future__ import print_function

n,m = [ int(i) for i in raw_input().split() ]
arr = [ map(int, raw_input().split()) for _ in xrange(n) ]    
k = int(raw_input())

arr.sort(key = lambda x: x[k])

for a in arr:
    print (*a)