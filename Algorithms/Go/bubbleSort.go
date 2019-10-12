package main

func bubbleSort(arr []int) {
	for {
		sorted := true
		for i := 0; i < len(arr)-1; i++ {
			if arr[i] > arr[i+1] {
				tmp := arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = tmp
				sorted = false
			}
		}
		if sorted == true {
			break
		}
	}
}
