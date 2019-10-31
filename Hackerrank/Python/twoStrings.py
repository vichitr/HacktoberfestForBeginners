#Author: turtlejump
#Issue: Two Strings: https://www.hackerrank.com/challenges/two-strings/

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the twoStrings function below.
def store(array, char):
    loc = hash(char) % len(array)
    array[loc].append(char)

def search(array, char):
    loc = hash(char) % len(array)
    for i in array[loc]:
        if i == char:
            return True
    return False

def twoStrings(s1, s2):
    map1 = [[] for i in range(len(s1))]
    # store all characters into a hash table
    for i in s1:
        store(map1, i)
    # if any of the characters inside s1 matches s2, then return 'YES'
    for i in s2:
        if search(map1, i) == True:
            return 'YES'
    return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()
