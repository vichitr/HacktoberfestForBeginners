import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        /* Maps names (keys) to phone numbers (values) */
        Map<String, Integer> phoneBook = new HashMap<>();

        int numEntries = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numEntries; i++) {
            String name = in.nextLine();
            int number = in.nextInt();
            in.nextLine();
            phoneBook.put(name, number);
        }

        while (in.hasNext()) {
            String name = in.nextLine();
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
