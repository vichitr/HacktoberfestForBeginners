/* ................. KMP Search in Java..........*/

import java.io.*;
import java.util.*;
import java.lang.*;
import java.util.Arrays;

public class Main
{
    
    public static int[] ll(String p, int l)
    {
        int lps[] = new int[l];
        int i = 0;
        int j = 1;
        lps[0] = 0;
        
        while(j<l)
        {
            if(p.charAt(i) == p.charAt(j))
            {
                i++;
                lps[j] = i;
                j++;
            }
            else
            {
                if(i!=0)
                {
                    i = lps[i-1];
                }
                else
                {
                    lps[j] = i;
                    j++;
                }
            }
        }
        return(lps);
    }
    
	public static void main(String[] args) throws IOException 
	{
		Scanner sc = new Scanner(System.in);
		String t = "dsgwadsgxdsgwadsgz";
		String p = "dsgwadsgz";
		System.out.println("Now the array is : "+p.length());
		int p1 = p.length(); 
		int lps[] = ll(p,p1);
		
		int t1 = t.length();
		int j = 0, i = 0;
		
		while(i<t1)
		{
		    if(t.charAt(i) == p.charAt(j))
		    {
		        i++;
		        j++;
		    }
		    if (j == p1) { 
                System.out.println("Found pattern "
                                   + "at index " + (i - j)); 
                j = lps[j - 1]; 
            } 
		    else
		    {
		        if(t.charAt(i) != p.charAt(j))
		        {
		          if(j!=0)
		          {
		              j = lps[j-1];
		          }
		          else
		          {
		              i++;
		          }
		        }
		    }
		}
	}
}
