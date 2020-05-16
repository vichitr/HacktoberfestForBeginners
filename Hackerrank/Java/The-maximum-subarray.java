//This code is contributed by Shreevatsa N, @vatsa287
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the maxSubarray function below.
    static int[] maxSubarray(int[] arr) {
        int ans = 0, wsum = 0, nonnegsum = 0; 
	//ans is the final answer when there is contigous subarray case, wsum is the subarray sum, nonnegsum is the sum of all non negative nos when we deal with non contigous elements.
        ans = wsum = arr[0];		//Using Kadanes Algorithm for this case of contigous subarray. So intialize the wsum , ans as arr[0] i.e is the first element.
        int ansArray[] = new int[2];	//Since we have to return the array having the result for two cases we set size as 2 which consits of the maxsum from both the est case respectiiely.
        
        for(int i=1;i<arr.length;i++)
        {   
            if(wsum + arr[i] > arr[i])
            {
                wsum+=arr[i];
            }
            else
            {
                wsum = arr[i];
            }
            ans = Math.max(ans,wsum);      //ans is the result for maximum subarray having contigous elements.
        }
        Arrays.sort(arr);			//Sort the array in order to find out if all elements are negative or not. If yes then the last element will be negative,
       System.out.println("ans is "+ arr[0]);
          if(arr[arr.length-1]<0)
          {
              nonnegsum = arr[arr.length-1];	//if all elements are negative then max amongst them is the last element in that sorted array.
          }
          else
          {
           for(int i=0;i<arr.length;i++)	//else add all the non negative nos to get the maximum result which are non contigous or subsequence.
          {   
              if(arr[i]>=0)
              nonnegsum+=arr[i];
          }
        }
        ansArray[0] = ans;
        ansArray[1] = nonnegsum;
        return ansArray;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            int n = scanner.nextInt();
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            int[] arr = new int[n];

            String[] arrItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int i = 0; i < n; i++) {
                int arrItem = Integer.parseInt(arrItems[i]);
                arr[i] = arrItem;
            }

            int[] result = maxSubarray(arr);

            for (int i = 0; i < result.length; i++) {
                bufferedWriter.write(String.valueOf(result[i]));

                if (i != result.length - 1) {
                    bufferedWriter.write(" ");
                }
            }

            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
