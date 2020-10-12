import java.math.BigInteger;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        in.close();

        BigInteger n = new BigInteger(str);
        System.out.println(n.isProbablePrime(10) ? "prime" : "not prime");
    }

}
