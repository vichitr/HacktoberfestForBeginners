/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;
interface AdvancedArithmetic{
  int divisor_sum(int n);
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class MyCalculator implements AdvancedArithmetic {

    /* Finds the sum of all divisors of the specified integer,
     * in O(n^1/2) time */
    public int divisor_sum(int n) {
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
class Solution{
    public static void main(String []args){
        MyCalculator my_calculator = new MyCalculator();
        System.out.print("I implemented: ");
        ImplementedInterfaceNames(my_calculator);
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(my_calculator.divisor_sum(n) + "\n");
      	sc.close();
    }
    /*
     *  ImplementedInterfaceNames method takes an object and prints the name of the interfaces it implemented
     */
    static void ImplementedInterfaceNames(Object o){
        Class[] theInterfaces = o.getClass().getInterfaces();
        for (int i = 0; i < theInterfaces.length; i++){
            String interfaceName = theInterfaces[i].getName();
            System.out.println(interfaceName);
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
