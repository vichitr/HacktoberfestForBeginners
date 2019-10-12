/* 
https://www.hackerrank.com/challenges/java-string-reverse/problem

Contributed by Bhushan Borole (https://github.com/bhushan-borole)
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        StringBuilder sb = new StringBuilder();
        sb.append(A);
        if(A.equals(sb.reverse().toString()))
            System.out.println("Yes");
        else
            System.out.println("No");
        
    }
}



