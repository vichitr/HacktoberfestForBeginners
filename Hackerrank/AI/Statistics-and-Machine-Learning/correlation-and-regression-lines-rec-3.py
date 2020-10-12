# Here are the test scores of 10 students in physics and history: 
# Physics Scores  15  12  8   8   7   7   7   6   5   3
# History Scores  10  25  17  11  13  17  20  13  9   15 
# When a student scores 10 in Physics, what is his probable score in History? 
# Compute the answer correct to one decimal place.

# Link: https://www.hackerrank.com/challenges/correlation-and-regression-lines-8
# Developer: Murillo Grubler

# Define functions
def mean(data):
    return sum(data) / len(data)

# Set data
physics = [15.0, 12.0, 8.0, 8.0, 7.0, 7.0, 7.0, 6.0, 5.0, 3.0]
history = [10.0, 25.0, 17.0, 11.0, 13.0, 17.0, 20.0, 13.0, 9.0, 15.0]

mean_physics = mean(physics)
mean_history = mean(history)

var_physics = sum([(p - mean_physics) ** 2 for p in physics])
sum_phy_his = 0
for i in range(len(physics)):
    sum_phy_his += (physics[i] - mean_physics) * (history[i] - mean_history)

# b = Σ(x - mean(x)) * (y - mean(y)) / Σ (x - mean(x))²
b = sum_phy_his / var_physics

# physics is x, variable independent
# history is y, variable dependent
# a = mean(y) - b * mean(x)
a = mean_history - b * mean_physics

# Y = b * X + a
result = b * 10 + a
print(round(result,1))