import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double payment = in.nextDouble();
        in.close();

        NumberFormat us     = NumberFormat.getCurrencyInstance(Locale.US);
        NumberFormat india  = NumberFormat.getCurrencyInstance
                                  (new Locale("en", "IN"));
        NumberFormat china  = NumberFormat.getCurrencyInstance(Locale.CHINA);
        NumberFormat france = NumberFormat.getCurrencyInstance(Locale.FRANCE);

        String usPayment     = us.format(payment);
        String indiaPayment  = india.format(payment);
        String chinaPayment  = china.format(payment);
        String francePayment = france.format(payment);

        System.out.println("US: "     + usPayment);
        System.out.println("India: "  + indiaPayment);
        System.out.println("China: "  + chinaPayment);
        System.out.println("France: " + francePayment);
    }

}
