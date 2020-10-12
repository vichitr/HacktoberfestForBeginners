# Objective 
# In this challenge, we practice calculating probability.

# Task 
# Bag1 contains 4 red balls and 5 black balls. 
# Bag2 contains 3 red balls and 7 black balls. 
# One ball is drawn from the Bag1, and 2 balls are drawn from 
# Bag2. Find the probability that 2 balls are black and 1 
# ball is red.

# Challenge: https://www.hackerrank.com/challenges/basic-probability-puzzles-4
# Reference: https://en.wikipedia.org/wiki/Probability
# GitHub: https://github.com/Murillo
# Developer: Murillo Grubler

# Combinations
# Bag1	Bag2	Bag2
# black	black	red
# black	red	    black
# red	black	black

# We have multiplied the possibilities
first_combination   = (5/9) * (7/10) * (3/9)
second_combination  = (5/9) * (3/10) * (7/9)
third_combination   = (4/9) * (7/10) * (6/9)

# Result = 0.4511111111111111 = 7/15
print (first_combination + second_combination + third_combination)