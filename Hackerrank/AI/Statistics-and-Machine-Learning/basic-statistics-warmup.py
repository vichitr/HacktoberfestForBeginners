# You are given an array of N integers separated by spaces, all in one line.
# Display the following:
# Mean (m): The average of all the integers.
# Median of this array: In case, the number of integers is odd, the middle element; 
# else, the average of the middle two elements.
# Mode: The element(s) which occurs most frequently. If multiple elements satisfy 
# this criteria, display the numerically smallest one.
# Standard Deviation (SD).
# SD = (((x1-m)2+(x2-m)2+(x3-m)2+(x4-m)2+...(xN-m)2))/N)0.5
# where xi is the ith element of the array
# Lower and Upper Boundary of the 95% Confidence Interval for the mean, separated 
# by a space. This might be a new term to some. However, it is an important concept 
# with a simple, formulaic solution. Look it up!

# Link: https://www.hackerrank.com/challenges/stat-warmup
# GitHub: https://github.com/Murillo
# Developer: Murillo Grubler

# Import libraries
import numpy as np
import math as m
import statistics as stpy
from scipy import stats

# Define function
def mean_confidence_interval(length, mean, stdev):
    return 1.96 * (stdev / m.sqrt(length))

# Input
total = int(input())
numbers = list(map(int, input().split()))

# Set statistics values
mean = np.mean(numbers)
median = np.median(numbers)
mode = int(stats.mode(numbers)[0])
stdev = stpy.pstdev(numbers)
confidence_interval = mean_confidence_interval(total, mean, stdev)
min_confidence = round(mean - confidence_interval, 1)
max_confidence = round(mean + confidence_interval, 1)

# Show the final result
print(round(mean,1))
print(round(median,1))
print(mode)
print(round(stdev,1))
print("{} {}".format(min_confidence, max_confidence))