/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.Scanner;

public class Solution {
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    /* Returns the smallest and largest substrings (newline-separated) of the
     * specified length from the given string. */
    private static String getSmallestAndLargest(String str, int k) {
        String initial = str.substring(0, k);

        String smallest = initial;
        String largest = initial;

        for (int i = 0; i <= str.length() - k; i++) {
            String current = str.substring(i, i + k);

            if (current.compareTo(smallest) < 0) {
                smallest = current;
            }
            if (current.compareTo(largest) > 0) {
                largest = current;
            }
        }

        return smallest + "\n" + largest;
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();

        System.out.println(getSmallestAndLargest(s, k));
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
