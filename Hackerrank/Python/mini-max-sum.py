#This code is contributed by Shreevatsa N, @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the miniMaxSum function below.
def miniMaxSum(arr):
    min_int = sum(arr) - max(arr)
    max_int = sum(arr) - min(arr)
    print(min_int, max_int)
if __name__ == '__main__':
    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
