#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the aVeryBigSum function below.
def aVeryBigSum(n,ar):
    sum=0
    for i in range(n):
        sum=sum+ar[i]
    return sum    


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = aVeryBigSum(ar_count,ar)

    fptr.write(str(result) + '\n')

    fptr.close()
