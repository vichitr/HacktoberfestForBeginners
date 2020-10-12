import java.util.Scanner;

class Solution {

    /* Performs a recursive DFS to check if the given game array is solvable
     * starting from the specified index */
    private static boolean isSolvable(int leap, int[] game, int i) {
        if (i < 0 || game[i] == 1) {
            return false;
        } else if (i + 1 >= game.length || i + leap >= game.length) {
            return true;
        }

        /* Don't go through this node again (avoids infinite recursion) */
        game[i] = 1;

        return isSolvable(leap, game, i + 1)
            || isSolvable(leap, game, i - 1)
            || isSolvable(leap, game, i + leap);
    }

    private static boolean canWin(int leap, int[] game) {
        return isSolvable(leap, game, 0);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int n = in.nextInt();
            int leap = in.nextInt();

            int[] game = new int[n];
            for (int j = 0; j < n; j++) {
                game[j] = in.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        in.close();
    }
}
