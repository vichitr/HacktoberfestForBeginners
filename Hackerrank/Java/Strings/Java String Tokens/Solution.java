import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        in.close();

        str = str.trim();

        if (str.length() > 400000) {
            return;
        } else if (str.length() == 0) {
            System.out.println(0);
            return;
        }

        String[] tokens = str.split("[^A-Za-z]+"); // consecutive letters

        System.out.println(tokens.length);
        for (String t : tokens) {
            System.out.println(t);
        }
    }

}
