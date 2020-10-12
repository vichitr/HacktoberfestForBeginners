# Charlie wants to buy a house. He does a detailed survey of the area where 
# he wants to live, in which he quantifies, normalizes, and maps the desirable 
# features of houses to values on a scale of 0 to 1 so the data can be assembled 
# into a table. If Charlie noted F features, each row contains F space-separated 
# values followed by the house price in dollars per square foot (making for a 
# total of F + 1 columns). If Charlie makes observations about H houses, his 
# observation table has H rows. This means that the table has a total 
# of (F + 1) * H entries.
# Unfortunately, he was only able to get the price per square foot for certain 
# houses and thus needs your help estimating the prices of the rest! Given the 
# feature and pricing data for a set of houses, help Charlie estimate the price 
# per square foot of the houses for which he has compiled feature data but 
# no pricing.

# Link: https://www.hackerrank.com/challenges/predicting-house-prices
# Reference: http://onlinestatbook.com/2/regression/intro.html
# Developer: Murillo Grubler

# Import library
from sklearn import linear_model

# Set data
features, rows = map(int, input().split())
X, Y = [], []

# Get the parameters X and Y for discovery the variables a and b
for i in range(rows):
    x = [0]
    elements = list(map(float, input().split()))
    for j in range(len(elements)):
        if j < features:
            x.append(elements[j])
        else:
            Y.append(elements[j])
    X.append(x)

# Set the model LinearRegression
model = linear_model.LinearRegression()
model.fit(X, Y)
a = model.intercept_
b = model.coef_

# Get the parameters X for discovery the Y
new_rows = int(input())
new_X = []
for i in range(new_rows):
    x = [0]
    elements = list(map(float, input().split()))
    for j in range(len(elements)):
        x.append(elements[j])
    new_X.append(x)

# Gets the result and show on the screen
result = model.predict(new_X)
for i in range(len(result)):
    print(round(result[i],2))