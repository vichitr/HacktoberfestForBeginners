/* ************************************************************************** */
/* --------------------------- begin locked code ---------------------------- */
import java.io.*;
import java.util.*;
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

    /* Traverses the tree rooted at the specified node in left-to-right level
     * order, and prints the data of all nodes in the order of traversal. */
    private static void levelOrder(Node root) {
        Queue<Node> queue = new ArrayDeque<>();
        StringBuilder traversal = new StringBuilder();

        if (root == null) {
            return;
        }

        queue.add(root);

        /* Beginning with the root, add the children (left, then right) of each
         * node to a queue; remove the node at the head of the queue and
         * iterate until all nodes have been processed in level-order */
        while (!queue.isEmpty()) {
            Node currentNode = queue.remove();
            traversal.append(currentNode.data + " ");

            if (currentNode.left != null) {
                queue.add(currentNode.left);
            }
            if (currentNode.right != null) {
                queue.add(currentNode.right);
            }
        }

        System.out.println(traversal);
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
            levelOrder(root);
        }
}
/* ---------------------------- end locked code ----------------------------- */
/* ************************************************************************** */
