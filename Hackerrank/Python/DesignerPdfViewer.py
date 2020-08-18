#This code is contributed by Shreevatsa N, @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the designerPdfViewer function below.
def designerPdfViewer(h, word):
    max1=0
    ch=''
    count = len(word)
    for ch in range(0,len(word)):
        if h[ ord(word[ch]) - 97  ] > max1:
            max1 = h[ord(word[ch]) - 97]
    return count * max1
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = list(map(int, input().rstrip().split()))

    word = input()

    result = designerPdfViewer(h, word)

    fptr.write(str(result) + '\n')

    fptr.close()
