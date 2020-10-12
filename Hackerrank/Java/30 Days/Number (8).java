/*
 * Just to pass the test cases for this challenge, it would be easiest to
 * just to iterate through the array backwards and print its elements.
 * Writing an efficient function to actually reverse the array is a much
 * better learning experience, however.
 */

import java.util.Scanner;

class Solution {

    /* Performs in-place array reversal. */
    private static void reverse(int[] array) {
        int head = 0;
        int tail = array.length - 1;

        while (head < tail) {
            int temp = array[head];
            array[head] = array[tail];
            array[tail] = temp;

            head++;
            tail--;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int length = in.nextInt();

        int[] array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = in.nextInt();
        }
        in.close();

        reverse(array);
        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

}
