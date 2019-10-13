const binarySearch = (array, element) => {

  let start = 0;
  let end = array.length;

  while (start <= end) {
    const mid = Math.floor((start + end)/2);
    if (array[mid] === element) {
      return true;
    } else if (array[mid] < element) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return false;
};

console.log(binarySearch([1, 3, 5, 6, 9, 10], 5));        // true
console.log(binarySearch([1, 3, 5, 6, 9, 10], 10));       // true
console.log(binarySearch([1, 3, 5, 6, 9, 10], 1));        // true
console.log(binarySearch([1, 3, 5, 6, 9, 10, 24], 6));    // true
console.log(binarySearch([1, 3, 5, 6, 9, 10, 24], 24));   // true
console.log(binarySearch([1, 3, 5, 6, 9, 10, 24], 1));    // true
console.log(binarySearch([1, 3, 5, 6, 9, 10], 7));        // false
console.log(binarySearch([], 6));                         // false
