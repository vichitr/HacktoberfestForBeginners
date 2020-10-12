/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.Scanner;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class UsernameValidator {
    static final String regularExpression = "^[A-Za-z]\\w{7,29}$";
}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */

public class Solution {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int n = Integer.parseInt(scan.nextLine());
        while (n-- != 0) {
            String userName = scan.nextLine();

            if (userName.matches(UsernameValidator.regularExpression)) {
                System.out.println("Valid");
            } else {
                System.out.println("Invalid");
            }
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
