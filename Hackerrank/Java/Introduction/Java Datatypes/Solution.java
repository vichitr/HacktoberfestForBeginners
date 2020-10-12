import java.util.Scanner;

class Solution {

    public static void main(String[] arg) {
        Scanner in = new Scanner(System.in);
        int numInputs = in.nextInt();

        for (int i = 0; i < numInputs; i++) {
            try {
                long x = in.nextLong();

                System.out.println(x + " can be fitted in:");

                if (x >= Byte.MIN_VALUE && x <= Byte.MAX_VALUE) {
                    System.out.println("* byte");
                }

                if (x >= Short.MIN_VALUE && x <= Short.MAX_VALUE) {
                    System.out.println("* short");
                }

                if (x >= Integer.MIN_VALUE && x <= Integer.MAX_VALUE) {
                    System.out.println("* int");
                }

                if (x >= Long.MIN_VALUE && x <= Long.MAX_VALUE) {
                    System.out.println("* long");
                }
            } catch (Exception e) {
                System.out.println(in.next() + " can't be fitted anywhere.");
            }
        }

        in.close();
    }

}
