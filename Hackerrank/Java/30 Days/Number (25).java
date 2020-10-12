/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
        next=null;
    }

}
class Solution
{
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    /* Removes all duplicate elements from the specified list, and returns
     * the reference to the head of that list (list MUST be in non-decreasing
     * order). */
    public static Node removeDuplicates(Node head) {
        if (head == null) {
            return null;
        }

        Node current = head;

        while (current.next != null) {
            /* Skip the next node, if it contains duplicate data */
            if (current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
    public static  Node insert(Node head,int data)
    {
        Node p=new Node(data);
        if(head==null)
            head=p;
        else if(head.next==null)
            head.next=p;
        else
        {
            Node start=head;
            while(start.next!=null)
                start=start.next;
            start.next=p;

        }
        return head;
    }
    public static void display(Node head)
        {
              Node start=head;
              while(start!=null)
              {
                  System.out.print(start.data+" ");
                  start=start.next;
              }
        }
        public static void main(String args[])
        {
              Scanner sc=new Scanner(System.in);
              Node head=null;
              int T=sc.nextInt();
              while(T-->0){
                  int ele=sc.nextInt();
                  head=insert(head,ele);
              }
              head=removeDuplicates(head);
              display(head);

       }
    }
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
