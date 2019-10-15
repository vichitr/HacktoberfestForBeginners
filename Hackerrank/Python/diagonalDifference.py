#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

n=int(input())
a=[]
for _ in range(n):
    x=list(map(int,input().split()))
    a.append(x)
s1=0
s2=0
for i in range(n):
    for j in range(n):
        
        if(i==j):
           
            s1+=a[i][j]
        if(i+j==n-1):
            
            s2+=a[i][j]
result=abs(s1-s2)
print(result)
        
