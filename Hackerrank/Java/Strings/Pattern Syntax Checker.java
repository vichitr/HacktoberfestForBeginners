/* 
https://www.hackerrank.com/challenges/pattern-syntax-checker/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

import java.util.Scanner;
import java.util.regex.*;

public class Solution
{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		while(testCases>0){
			String pattern = in.nextLine();
          	try{
                Pattern pat = Pattern.compile(pattern);
                System.out.println("Valid");
            }
            catch(Exception e){
                System.out.println("Invalid");
            }
		}
	}
}



