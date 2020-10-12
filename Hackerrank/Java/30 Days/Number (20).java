/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;

interface AdvancedArithmetic{
   int divisorSum(int n);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Calculator implements AdvancedArithmetic {

    /* Finds the sum of all divisors of the specified integer,
     * in O(n^1/2) time */
    public int divisorSum(int n) {
        int sum = 0;
        int sqrtN = (int) Math.sqrt(n);

        for (int i = 1; i <= sqrtN; i++) {
            if (n % i == 0) {
                /* Add both i and the corresponding factor, n/i, to the sum */
                sum += i;
                sum += n/i;
            }
        }

        /* If the square root of n is a divisor, the previous loop counted it
         * twice; so, subtract it from the sum once */
        if (sqrtN * sqrtN == n) {
            sum -= sqrtN;
        }

        return sum;
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();

      	AdvancedArithmetic myCalculator = new Calculator();
        int sum = myCalculator.divisorSum(n);
        System.out.println("I implemented: " + myCalculator.getClass().getInterfaces()[0].getName() );
        System.out.println(sum);
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
