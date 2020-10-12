/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.util.*;
import java.io.*;
class Node{
    Node left,right;
    int data;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */

    /* Returns the height of the binary tree rooted at the specified node,
     * where an empty tree has height -1, and a one-level tree has height 0. */
	public static int getHeight(Node root) {
        if (root == null) {
            return -1;
        } else {
            return 1 + Math.max(getHeight(root.left), getHeight(root.right));
        }
    }

/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
	public static Node insert(Node root,int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    public static void main(String args[]){
            Scanner sc=new Scanner(System.in);
            int T=sc.nextInt();
            Node root=null;
            while(T-->0){
                int data=sc.nextInt();
                root=insert(root,data);
            }
            int height=getHeight(root);
            System.out.println(height);
        }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
