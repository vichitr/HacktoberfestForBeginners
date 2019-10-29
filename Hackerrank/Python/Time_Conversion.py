# Author Name : Akshay Jain
#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    hh, mm, ssNu = s.split(':')
    ss = ssNu[:2]
    u = ssNu[2:]

    if u == 'AM' :
        if hh == '12' :
            hh = '00'
    else :
        if hh != '12' :
            hh = (int(hh) + 12 )
    return ("{}:{}:{}".format(hh, mm, ss))
if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
