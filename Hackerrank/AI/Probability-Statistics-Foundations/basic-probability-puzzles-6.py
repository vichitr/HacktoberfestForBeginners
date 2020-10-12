# Objective 
# In this challenge, we practice calculating probability.

# Task 
# Bag X contains 5 white balls and 4 black balls. Bag Y 
# contains 7 white balls and 6 black balls. You draw 1 ball 
# from bag X and, without observing its color, put it into 
# bag Y. Now, if a ball is drawn from bag Y, find the 
# probability that it is black.

# Challenge: https://www.hackerrank.com/challenges/basic-probability-puzzles-6
# Reference: https://en.wikipedia.org/wiki/Probability

# P(Y = b | X = w) * P(X = w) + P(Y = b | X = b) + P(X = b)
# (6/14 * 5/9) + (7/14 * 4/9) = 29/63 = 0.46031746

print ((6/14 * 5/9) + (7/14 * 4/9))