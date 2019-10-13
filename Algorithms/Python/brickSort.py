#FOr odd even
def oddEvenSort(arr, n): 
	isSorted = 0
	while isSorted == 0: 
		isSorted = 1
		temp = 0
		for i in range(1, n-1, 2): 
			if arr[i] > arr[i+1]: 
				arr[i], arr[i+1] = arr[i+1], arr[i] 
				isSorted = 0
				
		for i in range(0, n-1, 2): 
			if arr[i] > arr[i+1]: 
				arr[i], arr[i+1] = arr[i+1], arr[i] 
				isSorted = 0
	
	return


arr = [314, 20, 1, -9] 
n = len(arr) 

oddEvenSort(arr, n); 
print(arr)
