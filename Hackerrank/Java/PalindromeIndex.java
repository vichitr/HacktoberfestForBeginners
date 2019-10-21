import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

public static boolean palindrome(String s){
    StringBuffer sb = new StringBuffer();
        sb = sb.append(s);
        sb = sb.reverse();
        String n = sb.toString();
       if(n.equals(s)){
           return true;
       }
    else return false;
}
public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for(int a=0; a<n; a++){
        int out = 0;
        String input = sc.next();           
        if(palindrome(input)){
            System.out.println("-1");
        }
        else{
            for(int i=0; i<input.length(); i++){
                StringBuilder ss = new StringBuilder(input);
                if(input.charAt(i)!=input.charAt(input.length()-i-1)){
                 if(palindrome(ss.deleteCharAt(i).toString())){
                     System.out.println(i);
                 }
                    else System.out.println(input.length()-i-1);
                         break;
                }
            }
        }
    }
}
}
