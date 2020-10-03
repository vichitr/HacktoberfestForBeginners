/* ................. Advanced Navie Pattern Search in Java..........*/

import java.io.*;
import java.util.*;
import java.lang.*;

public class Main
{
    public void rk(String t, String p)
    {
        int t1 = t.length();
        int p1 = p.length();
        int i = 0;
        int j = 0;
        
        while(i<=t1-p1)
        {
            for(j = 0;j<p1;j++)
            {
                if(t.charAt(i+j) != p.charAt(j))
                {
                    break;
                }
            }
            if(j == p1)
            {
                System.out.println("Tne pattern is present at position : "+i);
                i = i+p1;
            }
            else if(j == 0)
            {
                i = i+1;
            }
            else
            {
                i = i+j;
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
