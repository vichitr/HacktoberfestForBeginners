/*
 * It's possible to solve this challenge in fewer lines by using inbuilt
 * functions (e.g., `Integer.toBinaryString()`) and performing lots of redundant
 * conditional or assignment statements while counting the ones. I've provided
 * both a general, reusable `toBinary()` function and an efficient approach to
 * counting the consecutive ones. These have more learning value for beginners.
 *
 * There is an interesting "shortcut" solution using the String class' `split()`
 * method - see if you can figure it out.
 */

import java.util.Scanner;

class Solution {

    /* Converts the specified base-10 integer to a binary string */
    private static String toBinary(int n) {
        String result = "";

        while (n > 0) {
            result = ((n % 2 == 1) ? "1" : "0") + result;
            n /= 2;
        }

        return result;
    }

    /* Returns the maximum number of consecutive ones in
     * the specified binary string. */
    private static int getMaxConsecutiveOnes(String str) {
        int current = 0;
        int max = 0;

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '1') {
                current++;
            } else if (current > 0) {
                // Only (potentially) update max at the end of a group of ones
                max = Math.max(max, current);
                current = 0;
            }
        }

        // May have ended on the longest streak of ones, so check max again
        return Math.max(max, current);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        String binaryString = toBinary(n);
        int result = getMaxConsecutiveOnes(binaryString);
        System.out.println(result);
    }

}
