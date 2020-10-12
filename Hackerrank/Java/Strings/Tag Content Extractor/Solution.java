/*
 * Regular expressions shouldn't be used in a real HTML parser. Nevertheless,
 * this challenge is presented as an exercise with regex in Java.
 */

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();
        in.nextLine();

        for (int t = 0; t < testCases; t++) {
            String input = in.nextLine();

            Pattern pattern = Pattern.compile("<(.+)>([^<]+)</\\1>");
            Matcher matcher = pattern.matcher(input);

            boolean foundMatch = false;

            while (matcher.find()) {
                System.out.println(matcher.group(2));
                foundMatch = true;
            }

            if (!foundMatch) {
                System.out.println("None");
            }
        }

        in.close();
    }

}
