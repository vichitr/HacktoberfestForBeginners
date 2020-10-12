import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Deque<Integer> deque = new ArrayDeque<>();
        HashSet<Integer> set = new HashSet<>();

        int n = in.nextInt();
        int m = in.nextInt();

        int maxUniqueElements = Integer.MIN_VALUE;

        /* Iterate through all contiguous subarrays, keeping track of the max
         * number of unique elements in any */
        for (int i = 0; i < n; i++) {
            int element = in.nextInt();

            deque.add(element);
            set.add(element);

            if (deque.size() == m) {
                if (set.size() > maxUniqueElements) {
                    maxUniqueElements = set.size();
                }

                int firstElement = deque.removeFirst();
                if (!deque.contains(firstElement)) {
                    set.remove(firstElement);
                }
            }
        }
        in.close();

        System.out.println(maxUniqueElements);
    }

}
