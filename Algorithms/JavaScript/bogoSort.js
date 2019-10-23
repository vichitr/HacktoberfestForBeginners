function isSorted(arr) {
  if (arr.length == 0 || arr.length == 1) {
    return true;
  }

  for (let i=0;i<arr.length-1;i++) {
    if (arr[i] > arr[i+1]) {
      return false;
    }
  }

  return true;
}

function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
      const j = Math.floor(Math.random() * (i + 1));
      [array[i], array[j]] = [array[j], array[i]];
  }
  return array;
}

function bogoSort(data) {
  while (!isSorted(data)) {
    data = shuffleArray(data);
  };
  return data;
}