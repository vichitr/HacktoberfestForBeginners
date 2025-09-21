#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'reverse_words_order_and_swap_cases' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING sentence as parameter.
#

def reverse_words_order_and_swap_cases(sentence):
    # Write your code here
    tsentence = sentence.swapcase()
    str = []
    buffer = tsentence.split(' ')
    for w in buffer:
        str.insert(0,w)
    
    return(" ".join(str))

if __name__ == '__main__':