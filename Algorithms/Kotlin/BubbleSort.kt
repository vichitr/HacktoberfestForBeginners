import java.util.*

fun input(): Array<Int>{
    //instance of Scanner class
    val reader: Scanner = Scanner(System.`in`)

    //creating the array
    println("enter size of array : ")
    var size:Int=reader.nextInt()
    var myArray=Array<Int>(size){0}

    //initializing the array
    for (i in 0..(size-1)){
        print("\nEnter element : ")
        myArray.set(i,reader.nextInt())
    }

    return myArray
}

fun display(myArray: Array<Int>){
    for (element in myArray)
        print(" "+ element)
}

fun main(args: Array<String>){
    var array=input()
    println("array before sorting : ")
    display(array)
    array=bubbleSort(array)
    println("\narray after sorting : ")
    display(array)

}

fun bubbleSort(array: Array<Int>): Array<Int> {

    for(i in 0..(array.size-2))
        for (j in 0..(array.size-2-i)){
            if(array.get(j+1)<array.get(j)){
                //swap
                var temp=array.get(j+1)
                array.set(j+1,array.get(j))
                array.set(j,temp)
            }
        }
    return array

}




