#Author: turtlejump
#Issue: Sherlock and Anagrams: https://www.hackerrank.com/challenges/sherlock-and-anagrams/

#!/bin/python3

import math
import os
import random
import re
import sys
from string import ascii_lowercase
# Complete the sherlockAndAnagrams function below.

def sherlockAndAnagrams(s):
    ALPHABET = ascii_lowercase

    sigs = {}

    sig = [0 for _ in ALPHABET]
    for letter in s:
        sig[ord(letter) - ord(ALPHABET[0])] += 1

    for i in range(len(s)):
        for j in range(i, len(s)):
            sig = [0 for _ in ALPHABET]
            for letter in s[i:j+1]:
                sig[ord(letter) - ord(ALPHABET[0])] += 1
            sig = tuple(sig)
            sigs[sig] = sigs.get(sig, 0) + 1
        res = 0
        for count in sigs.values():
            res += count * (count - 1)/2
    return int(res)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = sherlockAndAnagrams(s)

        fptr.write(str(result) + '\n')

    fptr.close()
