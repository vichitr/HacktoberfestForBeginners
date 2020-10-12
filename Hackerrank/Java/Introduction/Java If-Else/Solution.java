import java.util.Scanner;

class Solution {
    
    private static final int LOWER_LIMIT = 6;
    private static final int UPPER_LIMIT = 20;
    
    /*
     * - all odd numbers are weird
     * - even numbers in the range [LOWER_LIMIT, UPPER_LIMIT] are weird
     * - all other numbers are not weird
     */
    private static boolean isWeird(int n) {
        return (n % 2 == 1) || (LOWER_LIMIT <= n && n <= UPPER_LIMIT);
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
                
        String result = isWeird(n) ? "Weird" : "Not Weird";
        System.out.println(result);
    }
    
}