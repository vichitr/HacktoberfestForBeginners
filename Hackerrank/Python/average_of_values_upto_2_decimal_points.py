#!/bin/python3

import math
import os
import random
import re
import sys


# write your code here
def avg(*values):
    i=0
    sum=0
    for n in values:
        sum += n
        i = i+1
    a = float(sum/i)
    print("{0:.2f}".format(a))
    return(float("{0:.2f}".format(a)))
if __name__ == '__main__':
	avg(5,22,9,1.2)