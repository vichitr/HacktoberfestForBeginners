# A quick sort implementation in Python Lang

def swap(A, i, j):
    """This function is use to swap the i and j element of the array.
    Arguments Here are:\n
    \nA : an array to swap the values.
    \ni : index of first element to swap.
    \nj : index of second element to swap."""

    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def partition(A, l, r):
    # this function is used to partition the array and return the index of the sorted element(pivot).
    pivot  = A[(l+r)//2]
    i = l
    j = r

    while i <= j:
        while A[i] < pivot:
            i += 1

        while A[j] > pivot:
            j -= 1

        if i <= j:
            swap(A, i, j)
            i += 1
            j -= 1
    
    return i

def quicksort(A, l, r):
    """A function to sort the array in Asscending Order using Quick Sort Technique.\n
    Arguments : \n
    A : Array  to be sorted.\n
    l : left index of the array, generally 0.\n
    r : rightmost index of array, generally len(A) - 1."""
    # Recursive call for Quick Sort algorithm
    if l < r:
        index = partition(A, l, r)
        quicksort(A, l, index - 1)
        quicksort(A, index, r)

# Taking inputs
print("Enter an array : ")
array = list(map(int, input().split()))

# Printing the Unsorted array
print("Unsorted Array : " + str(array))

# Sorting the array
quicksort(array, 0, len(array) -1)

# Printing the sorted array
print("Sorted Array : " + str(array))



    
        


        

        