//This code is contributed by Shreevatsa N, @vatsa287
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the designerPdfViewer function below.
    static int designerPdfViewer(int[] h, String word) {

        int max = 0;
        int length = word.length();
        for(int i=0; i<length;i++)
        {
            char tempch = word.charAt(i);
            if(max < h[tempch - 97])
                max = h[tempch - 97];
        }
        return (max * length);

    }

//A matrix contaning values for every character is given, so the array has 26 values having the score of every alphabet.
//A word is given. We need to return the alphabet having maximum score * no of alphabets in the given word.
//Ex if a matrix has 1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 as its elements and word is abc we have to output 3 * 3 = 9
//3 for b having highest score amongst the given word and no of alpha is also 3
//The goal of the problem is to find which character in the given word has the highest ascii value and corresponding matrix values.
//It is all in lowercase, so we know that a is smallest having ascii value 97,
//We set max found to 0, then we traverse through the word given.We can know the position of the given word in the 26 ele pallet by just subtracting its ascii value to 97.
//Since 97 is start point we know for ex. e having ascii value 101 is at a distance 101 - 97 = 4 distance away from a, since matrix starts from 0 it will be in index 4 or pos 5, which is the right place of the character.
//We do this for all the elements present and find the alpha with highest value and multiply with no of elements in the word and return the same.
	
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int[] h = new int[26];

        String[] hItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < 26; i++) {
            int hItem = Integer.parseInt(hItems[i]);
            h[i] = hItem;
        }

        String word = scanner.nextLine();

        int result = designerPdfViewer(h, word);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
