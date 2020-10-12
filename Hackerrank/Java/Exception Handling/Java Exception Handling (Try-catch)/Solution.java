import java.util.InputMismatchException;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            // try to read input ints and print their quotient
            System.out.println(in.nextInt() / in.nextInt());
        } catch (InputMismatchException e) {
            // annoying way to print the exact expected output
            System.out.println(e.getClass().getName());
        } catch (ArithmeticException e) {
            // default output is fine for this exception
            System.out.println(e);
        }
    }

}
