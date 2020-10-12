/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.Scanner;

public class Solution {
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    private static boolean isAnagram(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }

        /* Maps each character to its number of occurences in string a
         * (unfortunately, we have to use the fully-qualified class name) */
        java.util.Hashtable<Character, Integer> hashtable =
            new java.util.Hashtable<Character, Integer>();

        a = a.toLowerCase();
        b = b.toLowerCase();

        for (int i = 0; i < a.length(); i++) {
            char ch = a.charAt(i);
            Integer numberOfOccurences = hashtable.get(ch);
            if (numberOfOccurences == null) {
                hashtable.put(ch, 1);
            }
            else {
                hashtable.put(ch, numberOfOccurences + 1);
            }
        }

        for (int i = 0; i < b.length(); i++) {
            char ch = b.charAt(i);
            Integer numberOfOccurences = hashtable.get(ch);

            if (numberOfOccurences == null) {
                /* If the hashtable doesn't contain a key value for the
                   character ch in the string b, then the string a contained
                   fewer occurences of  ch than b does, and the two cannot
                   be anagrams */
                return false;
            }
            else if (numberOfOccurences == 1) {
                hashtable.remove(ch);
            }
            else if (numberOfOccurences > 1) {
                hashtable.put(ch, numberOfOccurences - 1);
            }
        }

        /* If the hashtable is empty at this point, the strings contained the
           same characters in the same frequencies, and are anagrams */
        return hashtable.isEmpty();
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
  public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
