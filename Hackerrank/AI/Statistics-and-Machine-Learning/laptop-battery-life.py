# You will be able to access Fred’s laptop charging log by reading 
# from the file “trainingdata.txt”. The training data file will 
# consist of 100 lines, each with 2 comma-separated numbers. The 
# first number denotes the amount of time the laptop was charged 
# and the second denotes the amount of time the battery lasted. 
# The training data file can be downloaded here (this will be the 
# same training data used when your program is run). The input for
# each of the test cases will consist of exactly 1 number rounded 
# to 2 decimal places. For each input, output 1 number: the amount 
# of time you predict his battery will last.

# Link: https://www.hackerrank.com/challenges/battery
# GitHub: https://github.com/Murillo
# Developer: Murillo Grubler

# Import libraries
import sys
import pandas as pd
from sklearn import linear_model
import matplotlib.pyplot as plt

# Set dataset to training
dataset = pd.read_csv('dataset/trainingdata.txt', header=None)

# Plot the graph with the data
plt.plot(dataset.iloc[:,0], dataset.iloc[:,1], 'ro')
plt.ylabel('Laptob Battery Life')
plt.show()

# According to the chart, we must remove items with a 
# duration of time greater than eight.
dataset = dataset[dataset.iloc[:,1] < 8]

# Add bias
dataset.insert(0, len(dataset.columns), 0)

# Separe variables dependet and independent
X = dataset.iloc[:,0:2].as_matrix()
Y = dataset.iloc[:,2].as_matrix()

# Create the classifier model
model = linear_model.LinearRegression()
model.fit(X, Y)

# Set new value to predict
timeCharged = float(input().strip())
result = model.predict([[0, timeCharged]])
if result[0] > 8:
    print (8.0)
else:
    print (round(result[0],2))