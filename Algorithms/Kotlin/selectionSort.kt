fun selectionSort(A:Array<Int>){
    var n = A.size
    var temp: Int
    for(i in n-1 downTo 0){
        var max = i
        for(j in 0 until i){
            if(A[j] > A[max])
                max = j
        }
        if(i != max){
        temp = A[i]
        A[i]= A[max]
        A[max] = temp
       }
    }
}
