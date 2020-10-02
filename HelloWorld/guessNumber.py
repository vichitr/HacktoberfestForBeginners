#guess the Number using Python
'''
Program to Guess the Number that is choosen by Program itself & user will guess the Number, user will have limited chances to guess the number 
Random Number will be choosen from 1-50
'''

import random
n = random.randint(1,50)
print("Ranging from 1-50")
count = 4
while count:
    guess = int(input("Guess the number : "))
    if guess<n:
        print("The Number bigger than ",guess)
    elif guess>n:
        print("The Number is less than ",guess)
    else:
        print("You guess correct")
        break
    count=count-1
print("The number was",n)