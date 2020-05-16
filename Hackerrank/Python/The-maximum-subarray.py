#This code is contributed by Shreevatsa N, @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxSubarray function below.
def maxSubarray(arr):
    wsum,ans = arr[0],arr[0]
    nonnegsum = 0
    ansarray = []
    for i in range(1,len(arr)):
        wsum = max(arr[i],wsum+arr[i])
        ans = max(wsum,ans)
    arr.sort()
    if(arr[len(arr)-1]<0):
        nonnegsum = arr[len(arr)-1]
    else:
        for i in arr:
            if i >=0:
                nonnegsum+=i    
    ansarray.append(ans)
    ansarray.append(nonnegsum)
    return ansarray        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = maxSubarray(arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
