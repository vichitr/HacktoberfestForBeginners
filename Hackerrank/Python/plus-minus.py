#This code is contributed by Shreevatsa N, @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    length = len(arr)
    cpos , cneg ,czer = 0, 0, 0
    for i in range(0,length):
        if arr[i] > 0:		#counters for pos,neg and zero nus.
            cpos+=1
        elif arr[i] < 0:
            cneg+=1
        else:
            czer+=1
    print(cpos/length)		#no of pos/neg/zero nos divided by total nos.
    print(cneg/length)
    print(czer/length)
                    


if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
