#Author: turtlejump
#Issue: Hash Tables: Ransom Note: https://www.hackerrank.com/challenges/ctci-ransom-note/

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def store(array, word):
    # Hash the word (then squeeze it down to a smaller size)
    # Append it to the hashed location (assuming its a linked list)
    array[hash(word) % len(array)].append(word)
    

def retrieve(array, word):
    # Hash the word (squeeze it down to a smaller size)
    loc = hash(word) % len(array)
    # Loop through the particular hashed location, check for the word
    for i in range(len(array[loc])):
        if array[loc][i] == word:
            array[loc].pop(i)
            return True
    return False

def checkMagazine(magazine, note):
    # Implement a hash table
    # Our actual hash table
    magSize = len(magazine)
    mag = [[] for i in range(magSize)]
    for i in magazine:
        store(mag, i)
    for i in note:
        if retrieve(mag, i) == True:
            continue
        else:
            print('No')
            return
    print('Yes')
    return
if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
