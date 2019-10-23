fun main(args: Array<String>) {
    val array = readLine()!!.split(" ").map { it.toInt() }.toIntArray() 
    quickSort(array, 0, array.size-1)
    for(i in array) println(i)
}

fun quickSort(array: IntArray, left: Int, right: Int) {
    val index = partition (array, left, right)
    if(left < index-1) {
        quickSort(array, left, index-1)
    }
    if(index < right) {
        quickSort(array,index, right)
    }
}

fun partition(array: IntArray, l: Int, r: Int): Int {
    var left = l
    var right = r
    val pivot = array[(left + right)/2]
    while (left <= right) {
        while (array[left] < pivot) left++

        while (array[right] > pivot) right--
       
        if (left <= right) {
            swapArray(array, left,right)
            left++
            right--
        }
    }
    return left
}

fun swapArray(a: IntArray, b: Int, c: Int) {
    val temp = a[b]
    a[b] = a[c]
    a[c] = temp
}
