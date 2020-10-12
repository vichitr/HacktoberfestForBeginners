/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;

class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    /* Inserts a new node with the specified data at the end of the list whose
     * first node is `head`, and  returns the head of the resulting list */
    public static Node insert(Node head, int data) {
        Node newNode = new Node(data);

        /* Empty list case; insert new node as the only element */
        if (head == null) {
            return newNode;
        }

        /* Non-empty list case; traverse to end of list, then insert new node */
        Node currentNode = head;
        while (currentNode.next != null) {
            currentNode = currentNode.next;
        }
        currentNode.next = newNode;
        return head;
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
    public static void display(Node head) {
        Node start = head;
        while(start != null) {
            System.out.print(start.data + " ");
            start = start.next;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Node head = null;
        int N = sc.nextInt();

        while(N-- > 0) {
            int ele = sc.nextInt();
            head = insert(head,ele);
        }
        display(head);
        sc.close();
    }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
