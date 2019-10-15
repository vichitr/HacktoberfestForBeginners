// Author: Sai Kiran
// URL: https://www.hackerrank.com/challenges/maximum-element/problem
import java.io.*;
import java.util.*;

public class Solution {
    
    static class Stack {
        static Deque<Integer> stack = new ArrayDeque<Integer>();
        static Deque<Integer> maxValues = new ArrayDeque<Integer>();
        
        public static void push(int x) {
            stack.push(x);
            
            if (maxValues.isEmpty() || maxValues.peek() <= x) {
                maxValues.push(x);
            }
        }
        
        public static int getMax() {
            return maxValues.peek();
        }
        
        public static void pop() {
            if (stack.isEmpty()) return;
            
            int ret = stack.pop();
           
            if (ret == maxValues.peek()) {
                maxValues.pop();
            }
        }
    }
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        try {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int N = Integer.parseInt(line);
        
        Stack stack = new Stack();
        
        for (int i = 0; i < N; i++) {
            line = br.readLine();
            if (line.contains(" ")) {
                int num = Integer.parseInt(line.split(" ")[1]);
                stack.push(num);                
            } else if (line.equals("2")) {
                stack.pop();
            } else {
                System.out.println(stack.getMax());
            }
        }
        } catch (IOException e) {}
    }
}
