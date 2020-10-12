# You are given the scores of N students in three different subjects - 
# Mathematics,*Physics* and Chemistry; all of which have been graded 
# on a scale of 0 to 100. Your task is to compute the Pearson 
# product-moment correlation coefficient between the scores of different 
# pairs of subjects (Mathematics and Physics, Physics and Chemistry, 
# Mathematics and Chemistry) based on this data. This data is based on 
# the records of the CBSE K-12 Examination - a national school leaving 
# examination in India, for the year 2013.

# Link: https://www.hackerrank.com/challenges/computing-the-correlation
# Reference: https://en.wikipedia.org/wiki/Pearson_correlation_coefficient
# Developer: Murillo Grubler

# Import library
import math as m

# Define functions
def pearson(first_data, second_data, n):
    # Numerator part
    sum_firt_data       = sum(first_data)
    sum_second_data     = sum(second_data)
    sum_data            = sum([x*y for x,y in zip(first_data, second_data)])

    # Denominator part
    sum_first_data_squared      = sum([x**2 for x in first_data])
    sum_first_data_mult_squared = sum_firt_data ** 2
    sum_secon_data_squared      = sum([y**2 for y in second_data])
    sum_secon_data_mult_squared = sum_second_data ** 2

    numerator       = (n * sum_data) - (sum_firt_data * sum_second_data)
    den_first_data  = m.sqrt((n * sum_first_data_squared) - sum_first_data_mult_squared)
    den_second_data = m.sqrt((n * sum_secon_data_squared) - sum_secon_data_mult_squared)

    return round(numerator / (den_first_data * den_second_data), 2)


# Set data
n = int(input())
mathematics = []
physics     = []
chemistry   = []
for i in range(n):
    elements = list(map(float, input().split()))
    mathematics.append(elements[0])
    physics.append(elements[1])
    chemistry.append(elements[2])

# Show the correlation
print (pearson(mathematics, physics, float(n)))
print (pearson(physics, chemistry, float(n)))
print (pearson(mathematics, chemistry, float(n)))