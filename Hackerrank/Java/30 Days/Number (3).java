/*
 * Note that, in a real application, double/float values are NOT sufficiently
 * precise for currency manipulation. The Javadoc comments for Java's Currency
 * class recommend using BigDecimal instead.
 */

import java.util.Scanner;

class Solution {

    /* Note that calculations like this are exactly the sort of thing that
     * should be put in their own methods, for easy reuse and modularity */
    private static double findMealTotal(double mealCost,
            int tipPercent, int taxPercent) {
        double tipTotal = mealCost * tipPercent / 100;
        double taxTotal = mealCost * taxPercent / 100;

        return mealCost + tipTotal + taxTotal;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double mealCost = in.nextDouble();
        int tipPercent = in.nextInt();
        int taxPercent = in.nextInt();
        in.close();

        double mealTotal = findMealTotal(mealCost, tipPercent, taxPercent);
        System.out.println(Math.round(mealTotal));
    }

}
