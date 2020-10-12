import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String string = in.next();
            int parsed = Integer.parseInt(string);
            System.out.println(parsed);
        }
        catch (NumberFormatException e) {
            System.out.println("Bad String");
        }
    }

}
