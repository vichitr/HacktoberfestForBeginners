/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    static final int B;
    static final int H;
    static boolean flag;

    static {
        Scanner in = new Scanner(System.in);
        B = in.nextInt();
        H = in.nextInt();
        in.close();

        flag = true;

        try {
            if (B <= 0 || H <= 0) {
                flag = false;
                throw new Exception("Breadth and height must be positive");
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
public static void main(String[] args){
		if(flag){
			int area=B*H;
			System.out.print(area);
		}

	}//end of main

}//end of class
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
