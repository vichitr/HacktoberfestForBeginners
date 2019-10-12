/*
https://www.hackerrank.com/challenges/tag-content-extractor/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCases = Integer.parseInt(scan.nextLine());
        while (testCases > 0) {
            String line = scan.nextLine();
            boolean matchFound = false;
            Pattern r = Pattern.compile("<(.+)>([^<]+)</\\1>");
            Matcher m = r.matcher(line);
            while (m.find()) {
                System.out.println(m.group(2));
                matchFound = true;
            }
            if (!matchFound) {
                System.out.println("None");
            }
            testCases--;
        }
        scan.close();
    }
}

/*
Let me try to explain the regular expression:

<(.+)>
matches HTML start tags. The parentheses save the contents inside the brackets into Group #1.

([^<]+)
matches all the text in between the HTML start and end tags. 
We place a special restriction on the text in that it can't have the "<" symbol. 
The characters inside the parenthesis are saved into Group #2.

</\\1>
is to match the HTML end brace that corresponds to our previous start brace. The \1 is here to match all text from Group #1.
*/