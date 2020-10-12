import java.util.Scanner;

class Solution {

    /* Checks if the specified integer is prime, in O(n^1/2) time */
    private static boolean isPrime(int n) {
        if (n == 1) {             // 1 is defined to be composite
            return false;
        } else if (n == 2) {      // 2 is prime
            return true;
        } else if (n % 2 == 0) {  // 2 is the ONLY even prime
            return false;
        }

        /* A composite number must have a factor less than or equal to its
         * square root; check all potential odd factors up to that root */
        int sqrtN = (int) Math.sqrt(n);
        for (int f = 3; f <= sqrtN; f += 2) {
            if (n % f == 0) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();
        for (int i = 0; i < testCases; i++) {
            int n = in.nextInt();
            String result = (isPrime(n) ? "Prime" : "Not prime");
            System.out.println(result);
        }
        in.close();
    }

}
