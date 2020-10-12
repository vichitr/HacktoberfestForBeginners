import java.util.Deque;
import java.util.ArrayDeque;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

class Solution {

    private static final Map<Character, Character> map;

    static {
        map = new HashMap<>();
        map.put('(', ')');
        map.put('[', ']');
        map.put('{', '}');
    }

    private static boolean isBalanced(String str) {
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < str.length(); i++) {
            Character ch = str.charAt(i);

            if (map.containsKey(ch)) {
                stack.push(ch);
            } else if (stack.isEmpty() || ch != map.get(stack.pop())) {
                return false;
            }
        }

        return stack.isEmpty();
    }

	public static void main(String[] arg)
	{
		Scanner in = new Scanner(System.in);

		while (in.hasNext()) {
			String input = in.next();
            boolean isBalanced = isBalanced(input);
            System.out.println(isBalanced(input));
		}

        in.close();
	}

}
