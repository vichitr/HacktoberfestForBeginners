import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();

        for (int i = 0; i < testCases; i++) {
            int n = in.nextInt(); // inclusive upper limit of set {1, 2, ..., n}
            int k = in.nextInt(); // exclusive upper limit of (A & B) to return

            int maximumAND = 0;
            for (int a = 1; a < n; a++) {
                for (int b = a + 1; b <= n; b++) {
                    if ((a & b) < k && (a & b) > maximumAND) {
                        maximumAND = a & b;
                    }
                }
            }
            System.out.println(maximumAND);
        }
        in.close();
    }
}
