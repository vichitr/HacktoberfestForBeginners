//This code is contributed by Shreevatsa N, @vatsa287
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    public void LeftRotation(int n, int k, int a[])
    {   
        k = k%a.length;
        reverse(a,0,n-1);
        reverse(a,n-k,n-1);
        reverse(a,0,n-k-1);
        for(int i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
    }
    public int[] reverse(int a[],int start, int end)
    {
        while(start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
        return a;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] a = new int[n];

        String[] aItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int aItem = Integer.parseInt(aItems[i]);
            a[i] = aItem;
        }
        Solution obj = new Solution();
        obj.LeftRotation(n,d,a);
        scanner.close();
    }
}
