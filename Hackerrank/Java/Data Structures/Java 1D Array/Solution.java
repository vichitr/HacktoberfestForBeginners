/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;

public class Solution {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
        }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
        scan.close();

        // Prints each sequential element in array a
        for (int i = 0; i < a.length; i++) {
            System.out.println(a[i]);
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
