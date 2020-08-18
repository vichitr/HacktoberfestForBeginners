#This code is contributed by Shreevatsa N, @vatsa287

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    op = []	#remove the duplicates. 
    for ch in ar:
        if ch not in op:
            op.append(ch)
    count = 0	#intialize count of pairs to 0.
    for i in op:	#check the count of all elements in original list.
        if ar.count(i) == 1:	#if the no of duplicates is 0, then no pair available.
            count = count + 0
        elif ar.count(i)%2==1 and ar.count(i)>1:	#if count > 1 i.e pair and odd meaning one should be removed to form a pair.
            c = ar.count(i)
            c=c-1		#the removal is done here
            count = count + (c/2)	#since no of pair is required divide by 2.
        elif ar.count(i)%2==0 and ar.count(i)>1:	#if count > 1 i.e pair and its even , just divide by 2 to get no of pair socks present.
            count = count + ar.count(i)/2
        c = 0			#make c = 0 for next iteration so it is treated as a fresh case for next odd element.
    return(int(count))		#return the non decimal part.


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
