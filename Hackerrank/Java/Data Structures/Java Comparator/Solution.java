/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Checker implements Comparator<Player> {

    public int compare(Player p1, Player p2) {
        /* Scores should be sorted in descending order */
        int scoreDiff = Integer.compare(p2.score, p1.score);

        if (scoreDiff != 0) {
            return scoreDiff;
        } else {
            return (p1.name).compareTo(p2.name);
        }
    }

}

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
class Player{
    String name;
    int score;

    Player(String name, int score){
        this.name = name;
        this.score = score;
    }
}

class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        Player[] player = new Player[n];
        Checker checker = new Checker();

        for(int i = 0; i < n; i++){
            player[i] = new Player(scan.next(), scan.nextInt());
        }
        scan.close();

        Arrays.sort(player, checker);
        for(int i = 0; i < player.length; i++){
            System.out.printf("%s %s\n", player[i].name, player[i].score);
        }
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
