/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		    Scanner sc=new Scanner(System.in);
		    int T=sc.nextInt();
		   
		       
		    while(T-->0){
		   
		     int L=sc.nextInt();
		        int R=sc.nextInt();
		        int count=0;
		        for(int i=L;i<=R;i++)
		        {
		            int n=i%10;
		            if(n==2||n==3||n==9){
		                count++;
		            }
		        }
		        System.out.println(count);
		       
		        
		    }
		} catch(Exception e) {
		} finally {
		}
	}
}
