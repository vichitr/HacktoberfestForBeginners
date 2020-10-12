import java.util.Scanner;

class Solution {

    private static final int NUM_MULTIPLES = 10;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();

        for (int i = 1; i <= NUM_MULTIPLES; i++) {
            System.out.printf("%d x %d = %d\n", n, i, n * i);
        }
    }

}
