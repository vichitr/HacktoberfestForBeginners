/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.io.*;
import java.util.*;
import java.lang.*;


public class Main
{
    Node head;
    
    static class Node
    {
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }
    
    
    public void printl()
    {
        Node m = head;
        while(m!=null)
        {
            System.out.print(m.data+" ");
            m = m.next;
        }
    }
    
    public int count1(Node f)
    {
        if(f.next == null)
            return 0;
        
        return 1+count1(f.next);
    }
    
    
	public static void main(String[] args) {
// 		System.out.println("Hello World");
        
        Scanner sc = new Scanner(System.in);
        
		
		Main m = new Main();
		m.head = new Node(1);
		Node second = new Node(2);
		m.head.next = second;
		Node third = new Node(3);
		second.next = third;
		Node forth = new Node(5);
		third.next = forth;
		
		m.printl();
		
		System.out.println("Where do you want to insert the elment : 1 for start, 2. for middle 3. end");
		int l = sc.nextInt();
		System.out.println("Enter the value to be inserted");
		int f = sc.nextInt();
		if(l == 1)
		{
		    Node front = new Node(f);
		    front.next = m.head;
		    m.head = front;
		}
		
		else if(l == 2)
		{
		    System.out.println("Enter the position after which you want : ");
		    int p = sc.nextInt();
		    Node g = m.head;
		    int k = 0;
		    while(k!=(p-1))
		    {
		        g = g.next;
		        k++;
		    }
		    Node front = new Node(f);
		    front.next = g.next;
		    g.next = front;
		}
		else if(l == 3)
		{
		    Node g = m.head;
		    while(g.next!=null)
		    {
		        g = g.next;
		    }
		    Node front = new Node(f);
		  //  front.next = null;
		    g.next = front;
		}
		
		m.printl();
		int r = 1+m.count1(m.head);
		System.out.println("\nNumber of elements : "+r);
	}
}
