import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

class Solution {

    private static final String  REGEX = "@gmail.com$";
    private static final Pattern PATTERN = Pattern.compile(REGEX);

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numRows = in.nextInt();
        in.nextLine();

        /* Fill a list of names with all gmail users (i.e., regex matches) */
        List<String> names = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            String firstName = in.next();
            String emailID = in.next();

            Matcher matcher = PATTERN.matcher(emailID);
            if (matcher.find()) {
                names.add(firstName);
            }
        }
        in.close();

        /* Sort and print names of all gmail users */
        names.sort(null); // lexographical sort
        for (String name : names) {
            System.out.println(name);
        }
    }

}
