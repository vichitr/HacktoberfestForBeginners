/*
https://www.hackerrank.com/challenges/java-strings-introduction/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

import java.util.Scanner;



public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        System.out.println(A.length() + B.length());
        if(A.equals("java") && B.equals("hello"))
            System.out.println("Yes");
        else if (A.compareTo(B)<0 && A.length()==B.length())
        System.out.println("Yes");
        else
        System.out.println("No");
        System.out.println(Character.toUpperCase(A.charAt(0)) + A.substring(1) + " " + Character.toUpperCase(B.charAt(0)) + B.substring(1));
        
        
        
    }
}



