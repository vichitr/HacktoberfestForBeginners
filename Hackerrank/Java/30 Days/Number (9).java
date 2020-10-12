import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        /* Maps names (keys) to phone numbers (values) */
        Map<String, Integer> phoneBook = new HashMap<>();

        int numEntries = in.nextInt();
        for (int i = 0; i < numEntries; i++) {
            String name = in.next();
            int number = in.nextInt();
            phoneBook.put(name, number);
        }

        while (in.hasNext()) {
            String name = in.next();
            Integer number = phoneBook.get(name);

            if (phoneBook.containsKey(name)) {
                System.out.println(name + "=" + number);
            } else {
                System.out.println("Not found");
            }
        }

        in.close();
    }

}
