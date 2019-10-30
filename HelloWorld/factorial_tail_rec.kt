    # Factorial Using Tail Recursion
    fun main(args: Array<String>) {
        val number = 5
        println("Factorial of $number = ${factorial(number)}")
    }
    tailrec fun factorial(n: Int, run: Int = 1): Long {
        return if (n == 1) run.toLong() else factorial(n-1, run*n)
    }
