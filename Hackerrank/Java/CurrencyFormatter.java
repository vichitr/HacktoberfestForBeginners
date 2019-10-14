import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();
        NumberFormat d=NumberFormat.getCurrencyInstance();
         String us=d.format(payment);
        NumberFormat e=NumberFormat.getCurrencyInstance(Locale.CHINA);
        String china=e.format(payment);
         NumberFormat f=NumberFormat.getCurrencyInstance(Locale.FRANCE);
        // Write your code here.
        String france=f.format(payment);
        Locale a=new Locale("en","IN");
         NumberFormat g=NumberFormat.getCurrencyInstance(a);
        String india=g.format(payment);
        System.out.println("US: " + us);
        System.out.println("India: " + india);
        System.out.println("China: " + china);
        System.out.println("France: " + france);
    }
}
