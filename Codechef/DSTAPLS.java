import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
	   int T;
	   Scanner sc=new Scanner(System.in);
	   T=sc.nextInt();
	   for(int i=0;i<T;i++)
	    {
	        long N,K,a;
	        N=sc.nextLong();
	        K=sc.nextLong();
	        a=N/K;
	        if((a%K==0)||(K==1))
	        {
	            System.out.println("NO");
	        }
	        else
	            System.out.println("YES");
	    }
	  
	}
}
