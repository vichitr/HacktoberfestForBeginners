import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        int lineNumber = 1;

        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String currentLine = in.nextLine();
            System.out.printf("%d %s\n", lineNumber, currentLine);
            lineNumber++;
        }
        in.close();
    }

}
