#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    a=s[0:2]
    b=int(a)
    if(s[8]=="P"):
        if b<12:
            b+=12
    if(s[8]=="A"):
        if b==12:
            b = 0
    c=s[2:8]
    d = str(b)
    if b <10:
        d = '0'+d
    out=d+c
    return out


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
