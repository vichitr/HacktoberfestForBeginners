/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    Difference(int[] elements) {
        this.elements = elements;
        maximumDifference = 0;
    }

    /* Finds the maximum absolute difference between any two elements in
     * the `elements` array, and stores it in `maximumDifference` */
    void computeDifference() {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        /* Find the min and max elements - O(n) time, O(1) space */
        for (int element : elements) {
            if (element < min) {
                min = element;
            }

            if (element > max) {
                max = element;
            }
        }

        maximumDifference = Math.abs(max - min);
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
} // End of Difference class

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
