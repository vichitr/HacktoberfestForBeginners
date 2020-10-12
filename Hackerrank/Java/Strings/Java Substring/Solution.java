import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        int start  = in.nextInt();
        int end    = in.nextInt();
        in.close();

        System.out.println(str.substring(start, end));
    }

}
