# The two regression lines of a bivariate distribution are: 
# 4x – 5y + 33 = 0 (line of y on x) 20x – 9y – 107 = 0 (line of x on y). 
# Estimate the value of x when y = 7. Compute the correct answer to 
# one decimal place.

# Link: https://www.hackerrank.com/challenges/correlation-and-regression-lines-4
# Reference: https://stats.stackexchange.com/questions/22718/what-is-the-difference-between-linear-regression-on-y-with-x-and-x-with-y
# Developer: Murillo Grubler

# Estimate the value of x when y = 7
y = 7

# 20x – 9y – 107 = 0
val_x = (9 * y + 107) / 20

# Result: 8.5
print (round(val_x, 1))