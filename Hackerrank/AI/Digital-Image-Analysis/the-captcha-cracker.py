# You are provided a set of twenty-five captchas, such that, 
# each of the characters A-Z and 0-9 occur at least once in one 
# of the Captchas' text. From these captchas, you can identify 
# texture, nature of the font, spacing of the font, morphological 
# characteristics of the letters and numerals, etc. 

# Link: https://www.hackerrank.com/challenges/the-captcha-cracker
# Developer: Murillo Grubler

# Import libraries
import os
import sys
import numpy as np
from sklearn.linear_model import LogisticRegression
import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning) 

# Define functions
def getInput(directory, filename_input):
    pixels = []
    with open(directory + "/input/" + filename_input, "r") as f:
        next(f)
        for line in f:
            for item in line.split(" "):
                vals = [int(val) for val in item.split(",")]
                pixels.append(sum(vals)/len(vals))
    return pixels

def getOutput(directory, filename_input):
    label = "output" + str(filename_input[5:].split(".")[0]) + ".txt"
    with open(directory + "/output/" + label, "r") as f:
        return f.read().strip()

def getData(directory_name):
    inputs = []
    labels = []
    for root, dirs, files in os.walk(directory_name + "/input", topdown=False):
        files = [f for f in files if f.endswith(".txt")]
        for item in files:
            filename = os.path.join(root, item)
            labels.append(getOutput(directory_name, item))
            inputs.append(getInput(directory_name, item))
    
    return np.array(inputs), np.array(labels)

# Directory of the captcha
directory = sys.path[0] + "/sampleCaptchas"

# Read the captchas
input_data, output_data = getData(directory)

# Create the classifier model
clf = LogisticRegression()
clf.fit(input_data, output_data)

# Set new captcha
image = []
row, col = map(int,input().split(' '))
for i in range(row):
    line = input()
    for item in line.split(" "):
        vals = [int(val) for val in item.split(",")]
        image.append(sum(vals)/len(vals))

print(clf.predict(image)[0])
