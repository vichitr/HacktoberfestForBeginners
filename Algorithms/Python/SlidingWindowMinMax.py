# Sliding window technique for finding max/ min window sum
# Integer array and window size are randomly generated
# Done in a Pythonic way

import random
import math

def slidingWindowFind(minmax, data, winSize):
    # Check for invalid window size
    if (len(data) < winSize):
        print("Cannot perform sliding window - window size must be less than array length")
        return None
    
    ret = None
    
    # Sum up the first window
    if (minmax == 0):
        print("Finding the minimum window")
        print("\t Array: " + str(data))
        print("\t Window size: " + str(winSize))
        
        # Starting min value is infinity
        ret = float("inf")
        
        # Sliding window
        for i in range(winSize, len(data)):
            # Slide window forward by 1 element each time
            currentSum = sum(data[i-winSize:i])
            print("Current window: " + str(data[i-winSize:i]))
            print("Window sum: " + str(currentSum))
            print("Current min: " + str(ret))
            
            ret = min(ret, currentSum)
        
    elif(minmax == 1):
        print("Finding the maximum window")
        print("\t Array: " + str(data))
        print("\t Window size: " + str(winSize))
        
        # Starting min value is negative infinity
        ret = float("-inf")
        
        # Sliding window
        for i in range(winSize, len(data)):
            # Slide window forward by 1 element each time
            currentSum = sum(data[i-winSize:i])
            print("Current window: " + str(data[i-winSize:i]))
            print("Window sum: " + str(currentSum))
            print("Current max: " + str(ret))
            
            ret = max(ret, currentSum)
        
    else:
        print("Invalid sliding window option - use 0 for min, and 1 for max")
        return None
    
    return ret
        
        
if __name__== "__main__":
    array = []
    
    # Generate random array with random length between 10 and 20 elements
    for i in range(random.randint(9,20)):
        array.append(random.randint(1, 11)) # Append random number between 1 and 10
    
    winSize = random.randint(2, 6) # Generate random window size between 2 and 5
    
    print("Run sliding window to find max and min...")
    minVal = slidingWindowFind(0, array, winSize)
    print("\n")
    maxVal = slidingWindowFind(1, array, winSize)
    
    print("\nMinimum sum:" + str(minVal))
    print("Maximum sum:" + str(maxVal))
    
        
        