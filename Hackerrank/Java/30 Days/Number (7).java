/*
 * Note that strings in Java are immutable. A consequence of this is that
 * a new String object is created each time a string is concatenated with a
 * another string. This is inefficient, if the concatenation is to be
 * repeated many times (for example, if the text of an entire book was the
 * input to this class). In that case, a mutable string class like StringBuilder
 * should be used.
 *
 * Alternatively, for the purposes of passing the test cases for this challenge,
 * you could just print the characters out without saving any strings at all.
 */

import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();
        in.nextLine();

        for (int t = 0; t < testCases; t++) {
            String input = in.nextLine();

            StringBuilder evenChars = new StringBuilder();
            StringBuilder oddChars = new StringBuilder();

            for (int i = 0; i < input.length(); i++) {
                if (i % 2 == 0) {
                    evenChars.append(input.charAt(i));
                } else {
                    oddChars.append(input.charAt(i));
                }
            }

            System.out.println(evenChars + " " + oddChars);
        }

        in.close();
    }

}
