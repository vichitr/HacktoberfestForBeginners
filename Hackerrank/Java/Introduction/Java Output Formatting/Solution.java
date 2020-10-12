import java.util.Scanner;

class Solution {

    private static final int NUM_LINES = 3;

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        System.out.println("================================");
        for (int j = 0; j < NUM_LINES; j++)
        {
            String s = in.next();
            int i = in.nextInt();

            System.out.printf("%-15s%03d\n", s, i);
        }
        System.out.println("================================");

        in.close();
    }

}
