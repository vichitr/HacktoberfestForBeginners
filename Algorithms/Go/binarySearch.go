package main
import "fmt"

func binarySearch(array []int, element int) bool {
    if (len(array) == 0) {
        return false;
    }
    start := 0
    end := len(array)
    for (start <= end) {
        mid := (start + end)/2
        if (array[mid] == element) {
            return true
        } else if (array[mid] < element) {
            start = mid + 1
        } else {
            end = mid - 1
        }
    }
	return false;
}

func binarySearchWithRecursion(array []int, element int) bool {
        if (len(array) == 0) {
            return false;
        }
        start := 0
        end := len(array)
        mid := (start + end)/2
        if (array[mid] == element) {
            return true
        } else if (array[mid] < element) {
            return binarySearchWithRecursion(array[mid+1:end], element)
        }
        return binarySearchWithRecursion(array[start:end-1], element)

}

func main() {
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10}, 5));          // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10}, 10));         // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10}, 1));          // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10, 24}, 6));      // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10, 24}, 24));     // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10, 24}, 1));      // true
  fmt.Println(binarySearch([]int{1, 3, 5, 6, 9, 10}, 7));          // false
  fmt.Println(binarySearch([]int{}, 6));                           // false

  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10}, 5));          // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10}, 10));         // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10}, 1));          // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10, 24}, 6));      // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10, 24}, 24));     // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10, 24}, 1));      // true
  fmt.Println(binarySearchWithRecursion([]int{1, 3, 5, 6, 9, 10}, 7));          // false
  fmt.Println(binarySearchWithRecursion([]int{}, 6));                           // false
}
