/*
 * Note that the fine policy defined in this problem is pretty silly;
 * for example, "a year early" and "a year late" are determined by
 * comparing JUST the year values, such that 12/31/2017 and 1/1/2018
 * are "a year apart".
 */

import java.util.Scanner;

class Solution {

    /* Computes the fine amount (which may be 0), given the actual and expected
     * dates of return */
    private static int getFine(int actDay, int actMonth, int actYear,
                               int expDay, int expMonth, int expYear) {
        int fine = 0;

        if (actYear == expYear) {
            if (actMonth == expMonth && actDay > expDay) {
                // returned in expected year and month, at least a day late
                fine = 15 * (actDay - expDay);
            } else if (actMonth > expMonth) {
                // returned in expected year, at least a month late
                fine = 500 * (actMonth - expMonth);
            }x
        } else if (actYear > expYear) {
            // returned at least a year late
            fine = 10000;
        }

        return fine;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        /* Read the actual return date */
        int actDay = in.nextInt();
        int actMonth = in.nextInt();
        int actYear = in.nextInt();

        /* Read the expected return date */
        int expDay = in.nextInt();
        int expMonth = in.nextInt();
        int expYear = in.nextInt();

        in.close();

        int fine = getFine(actDay, actMonth, actYear,
                           expDay, expMonth, expYear);

        System.out.println(fine);
    }

}
