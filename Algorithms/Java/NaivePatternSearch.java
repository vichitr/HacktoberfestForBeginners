/* ................. Navie Pattern Search in Java..........*/
import java.io.*;
import java.lang.*;
import java.util.*;

public class Main
{
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    String p = sc.nextLine();
	    String t = sc.nextLine();
	    
	    int p1 = p.length();
	    int t1 = t.length();
	    
	    if(t1>p1)
	    {
	        System.out.println("Not possible");
	    }
	    else
	    {
	        
	        for(int i = 0;i<=p1-t1;i++)
	        {
	            String g = p.substring(i,i+t1);
	            if(g.equals(t))
	            {
	                System.out.println("The text is present at position : "+i);
	            }
	        }
	    }
	}
}
