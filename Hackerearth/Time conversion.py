#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    hour = int(s[:2])
    meridian = s[8:]
# Special-case '12AM' -> 0, '12PM' -> 12 (not 24)
    if (hour == 12):
        hour = 0
    if (meridian == 'PM'):
        hour += 12
    return ("%02d" % hour + s[2:8])

    


   

    #
    # Write your code here.
    #

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
