/*............... Rabin-Karp.................*/

import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
    final int f = 29;
    
    public int hash(String s)
    {
        int sum = 0;
        for(int i = 0;i<s.length();i++)
        {
            sum += (int)s.charAt(i);
        }
        System.out.println(sum%f);
        return(sum%f);
    }
    
    public void rk(String t, String p)
    {
        int t1 = t.length();
        int p1 = p.length();
        int ph = hash(p);
        
        for(int i = 0;i<t1-p1;i++)
        {
            String g = t.substring(i,i+p1);
            int l = hash(g);
            if(l == ph)
            {
                if(g.equals(p))
                {
                    System.out.println("Tne pattern is present at position : "+i);
                }
            }
        }
    }
    
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the text");
		String t = sc.nextLine();
		System.out.println("ENter the pattern");
		String p = sc.nextLine();
		Main m = new Main();
		m.rk(t,p);
	}
}
