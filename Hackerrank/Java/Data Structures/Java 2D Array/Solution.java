/*
 * It would be possible to make this solution even less hardcoded by specifying
 * the width of an hourglass, or even its entire shape. However, that just
 * doesn't feel like a good use of anyone's time.
 */

import java.util.Scanner;

class Solution {

    private static final int ROWS = 6;
    private static final int COLS = 6;

    /* Returns the sum of the hourglass whose upper-left index is array[r][c] */
    private static int hourglassSum(int[][] array, int r, int c) {
        return
            array[r + 0][c + 0] + array[r + 0][c + 1] + array[r + 0][c + 2]
                                + array[r + 1][c + 1] +
            array[r + 2][c + 0] + array[r + 2][c + 1] + array[r + 2][c + 2];
    }

    /* Returns the maximum sum of all hourglasses in the specified array */
    private static int maxHourglassSum(int[][] array) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int r = 0; r <= ROWS - 3; r++) {
            for (int c = 0; c <= COLS - 3; c++) {
                currentSum = hourglassSum(array, r, c);

                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }

        return maxSum;
    }

    public static void main(String[] args) {
        int[][] array = new int[ROWS][COLS];

        // Read in the 2D array
        Scanner in = new Scanner(System.in);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {;
                array[r][c] = in.nextInt();
            }
        }
        in.close();

        System.out.println(maxHourglassSum(array));
    }

}
