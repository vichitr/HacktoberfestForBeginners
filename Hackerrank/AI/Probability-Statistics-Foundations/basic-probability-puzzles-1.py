# Objective 
# In this challenge, we practice calculating probability.

# Task
# In a single toss of 2 fair (evenly-weighted) 6-sided dice, 
# find the probability of that their sum will be at most 9.

# Challenge: https://www.hackerrank.com/challenges/basic-probability-puzzles-1
# Reference: https://en.wikipedia.org/wiki/Probability
# GitHub: https://github.com/Murillo
# Developer: Murillo Grubler

probability = 1/6
values = 6
result = 0

# First dice
for i in range(1, values + 1):
    # Second dice
    for j in range(1, values + 1):
        # Verify if each die will be different and their sum is 6
        if (i + j) <= 9:
            result += probability ** 2

# Final probability found
print (result)