/*
 * This challenge is an exercise in reading Oracle's Java API documentation.
 * While the HackerRank editorial solution uses a Stack and LinkedList for
 * the stack and queue, respectively, the class comments explicitly suggest
 * using ArrayDeque over Stack, and indicate that ArrayDeque generally runs
 * faster than both Stack and LinkedList when used as a stack or queue.
 */

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

class Solution {

    private Deque<Character> stack = new ArrayDeque<>();
    private Deque<Character> queue = new ArrayDeque<>();

    /* Pushes a character onto the stack */
    private void pushCharacter(char ch) {
        stack.push(ch);
    }

    /* Enqueues a character in the queue */
    private void enqueueCharacter(char ch) {
        queue.add(ch);
    }

    /* Pops and returns the character at the top of the stack */
    private char popCharacter() {
        return stack.pop();
    }

    /* Dequeues and returns the first character in the queue */
    private char dequeueCharacter() {
        return queue.remove();
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        scan.close();

        // Convert input String to an array of characters:
        char[] s = input.toCharArray();

        // Create a Solution object:
        Solution p = new Solution();

        // Enqueue/Push all chars to their respective data structures:
        for (char c : s) {
            p.pushCharacter(c);
            p.enqueueCharacter(c);
        }

        // Pop/Dequeue the chars at the head of both data structures and compare them:
        boolean isPalindrome = true;
        for (int i = 0; i < s.length/2; i++) {
            if (p.popCharacter() != p.dequeueCharacter()) {
                isPalindrome = false;
                break;
            }
        }

        //Finally, print whether string s is palindrome or not.
        System.out.println( "The word, " + input + ", is "
                           + ( (!isPalindrome) ? "not a palindrome." : "a palindrome." ) );
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
