import java.util.Scanner;

class Solution {

    private static final int NUM_INTS = 3;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < NUM_INTS; i++) {
            System.out.println(in.nextInt());
        }
        in.close();
    }

}
