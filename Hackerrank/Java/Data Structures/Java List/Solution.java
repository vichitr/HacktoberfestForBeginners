import java.io.*;
import java.util.*;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        /* Add initial elements to the list */
        int numElements = in.nextInt();
        in.nextLine();
        List<Integer> list = new LinkedList<>();
        for (int i = 0; i < numElements; i++) {
            list.add(in.nextInt());
        }

        /* Run insertions/deletions on the list */
        int numQueries = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numQueries; i++) {
            String operation = in.nextLine();

            if (operation.equals("Insert")) {
                list.add(in.nextInt(), in.nextInt());
            } else if (operation.equals("Delete")) {
                list.remove(in.nextInt());
            }

            if (in.hasNext()) {
                in.nextLine();
            }
        }
        in.close();

        /* Print the final list */
        for (int i : list) {
            System.out.print(i + " ");
        }
    }

}
