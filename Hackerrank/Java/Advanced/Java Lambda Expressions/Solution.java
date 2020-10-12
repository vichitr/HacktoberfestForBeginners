/*
 * Code indented by ONE space...wow.
 */

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
interface PerformOperation {
 boolean check(int a);
}
class MyMath {
 public static boolean checker(PerformOperation p, int num) {
  return p.check(num);
 }
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    static PerformOperation isOdd() {
        return (int a) -> (a % 2 != 0);
    }

    static PerformOperation isPrime() {
        return (int a) -> java.math.BigInteger.valueOf(a).isProbablePrime(16);
    }

    static PerformOperation isPalindrome() {
        return (int i) -> Integer.toString(i).equals(new
                StringBuilder(Integer.toString(i)).reverse().toString());
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
public class Solution {

 public static void main(String[] args) throws IOException {
  MyMath ob = new MyMath();
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  int T = Integer.parseInt(br.readLine());
  PerformOperation op;
  boolean ret = false;
  String ans = null;
  while (T--> 0) {
   String s = br.readLine().trim();
   StringTokenizer st = new StringTokenizer(s);
   int ch = Integer.parseInt(st.nextToken());
   int num = Integer.parseInt(st.nextToken());
   if (ch == 1) {
    op = ob.isOdd();
    ret = ob.checker(op, num);
    ans = (ret) ? "ODD" : "EVEN";
   } else if (ch == 2) {
    op = ob.isPrime();
    ret = ob.checker(op, num);
    ans = (ret) ? "PRIME" : "COMPOSITE";
   } else if (ch == 3) {
    op = ob.isPalindrome();
    ret = ob.checker(op, num);
    ans = (ret) ? "PALINDROME" : "NOT PALINDROME";

   }
   System.out.println(ans);
  }
 }
}

/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
