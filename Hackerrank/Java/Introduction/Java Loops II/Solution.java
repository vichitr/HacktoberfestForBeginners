import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int NUM_QUERIES = in.nextInt();

        for (int i = 0; i < NUM_QUERIES; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();

            for (int j = 1; j <= n; j++) {
                System.out.printf("%d ", a + b * (int) (Math.pow(2, j) - 1));
            }
            System.out.println();
        }

        in.close();
    }
}
