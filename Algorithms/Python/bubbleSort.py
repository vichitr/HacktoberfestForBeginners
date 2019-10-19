# bubble sort

# test numbers
toSort = [3, 7, 2, 6, 4]

# perform bubble sort
for i in range(5):
    for j in range(4):
        if toSort[j] > toSort[j+1]:
            temp = toSort[j]
            toSort[j] = toSort[j + 1]
            toSort[j + 1] = temp

# print sorted list
for x in toSort:
    print(x)
