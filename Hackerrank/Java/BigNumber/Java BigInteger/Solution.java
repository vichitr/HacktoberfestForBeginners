import java.util.Scanner;
import java.math.BigInteger;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a = new BigInteger(in.next());
        BigInteger b = new BigInteger(in.next());
        in.close();

        System.out.println(a.add(b));
        System.out.println(a.multiply(b));
    }
}
