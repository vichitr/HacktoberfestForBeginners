import java.util.Scanner;

class Solution {

    private static long factorial(int n) {
        /* Base case */
        if (n == 0) {
            return 1;
        }

        /* Recursive case */
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();

        System.out.println(factorial(n));
    }

}
