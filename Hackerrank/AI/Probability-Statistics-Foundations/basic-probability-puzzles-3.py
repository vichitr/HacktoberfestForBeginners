# Objective 
# In this challenge, we practice calculating probability.

# Task
# There are 3 urns: X, Y and Z.
# Urn X contains 4 red balls and 3 black balls.
# Urn Y contains 5 red balls and 4 black balls.
# Urn Z contains 4 red balls and 4 black balls.
# One ball is drawn from each urn. What is the probability 
# that the 3 balls drawn consist of 2 red balls and 1 black ball?

# Challenge: https://www.hackerrank.com/challenges/basic-probability-puzzles-3
# Reference: https://en.wikipedia.org/wiki/Probability
# GitHub: https://github.com/Murillo
# Developer: Murillo Grubler

# Combinations
#Urn X	Urn Y	Urn Z
#red	red	    black
#black	red	    red
#red	black	red

x_prob_red = 4/7
x_prob_black = 3/7

y_prob_red = 5/9
y_prob_black = 4/9

z_prob_red = 1/2
z_prob_black = 1/2

# We have multiplied the possibilities
first_combination   = x_prob_red * y_prob_red * z_prob_black
second_combination  = x_prob_black * y_prob_red * z_prob_red
third_combination   = x_prob_red * y_prob_black * z_prob_red

# Result = 0.40476190476190477 = 17/42
print (first_combination + second_combination + third_combination)