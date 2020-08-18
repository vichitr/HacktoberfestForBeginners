#This code is contributed by Shreevatsa N , @vatsa287
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gradingStudents' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY grades as parameter.
#

def gradingStudents(grades):
    # Write your code here

    list1 = []
    for n in grades:
        print(n)
        if n >= 38 and n <= 100:      #check if marks is within this range
            if n%5 == 3 or n%5==4 :   #if the remainder with 5 is either 3 or 4 since 5rem is treated as 0
                if n%10 > 5:	      #unit place is greater > 5	
                    temp = 10-n%10    	
                    n = n + temp      #add the required difference for round off
                    list1.append(n)
                elif n%10 < 5:
                    temp = 5 - n%10
                    n = n + temp
                    list1.append(n)
            elif n%5 == 0 or n%5 == 1 or n%5 == 2:	#if the difference between the marks and next multiple is less than 3
                list1.append(n)
        else:				#if marks is out of range then no rounding up
            list1.append(n)
    return(list1)        


        



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
