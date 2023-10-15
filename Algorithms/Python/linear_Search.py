#python code for linear search
MAX = 20
#array of items on which linear search will be conducted.
intArray = [1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66]
def printline(count):
    for i in range(count-1):
        print("=", end="")
    print("=")
#this method makes a linear search. 
def find(data):
    comparisons = 0
    index = -1
    #navigate through all items
    for i in range(MAX):
        #count the comparisons made
        comparisons += 1
        
        #if data found, break the loop
        if data == intArray[i]:
            index = i
            break
    print("Total comparisons made:", comparisons)
    return index
def display():
    print("[", end="")
    #navigate through all items 
    for i in range(MAX):
        print(intArray[i], end=" ")
    print("]")
print("Input Array: ", end="")
display()
printline(50)
#find location of 1
location = find(55)
#if element was found 
if location != -1:
    print("\nElement found at location:", location+1)
else:
    print("Element not found.")