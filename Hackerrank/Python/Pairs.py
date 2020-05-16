#This code is contributed by Shreevatsa N, @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the pairs function below.
def pairs(k, arr):
    s = {};
    count=0
    for i in arr: #add all elements to the set, it does not have any duplicates present.
        s[i] = i
    for a in arr:  #for every element in the array, check if its complement exists in the set.
        g = a + k   #complement = array ele + given target
        if g in s:      #if complement is present in the set, it means that already found and added so increment counter
            count+=1
    return count;

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    arr = list(map(int, input().rstrip().split()))

    result = pairs(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
