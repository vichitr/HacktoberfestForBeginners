/*
 * This solution ONLY allows you to modify the three lines numbered below.
 * Even including this comment will cause it to fail.
 */

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class DuplicateWords {

    public static void main(String[] args) {

        String regex = "\\b(\\w+)(\\W+\\1\\b)+";                        // 1
        Pattern p = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);   // 2

        Scanner in = new Scanner(System.in);
        int numSentences = Integer.parseInt(in.nextLine());

        while (numSentences-- > 0) {
            String input = in.nextLine();

            Matcher m = p.matcher(input);

            // Check for subsequences of input that match the compiled pattern
            while (m.find()) {
                input = input.replaceAll(m.group(), m.group(1));        // 3
            }

            // Prints the modified sentence.
            System.out.println(input);
        }

        in.close();
    }
}
