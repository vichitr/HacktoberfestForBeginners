import java.util.Scanner;

class BSTNode{
    int data;
    BSTNode left;
    BSTNode right;
    public BSTNode(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
public class BST {
    private BSTNode root;
    public BST(){
        this.root = null;
    }

    private boolean searchHelper(BSTNode root, int data){
        if(root == null)
            return false;
        if(root.data > data)
            return searchHelper(root.left, data);
        else if(root.data < data)
            return searchHelper(root.right, data);
        else
            return true;
    }

    public boolean search(int data){
        return searchHelper(root, data);
    }

    private BSTNode addHelper(BSTNode root, int data){
        if(root == null){
            root = new BSTNode(data);
            return root;
        }
        if(root.data > data)
            root.left = addHelper(root.left, data);
        else if(root.data < data)
            root.right = addHelper(root.right, data);
        return root;
    }

    public void add(int data){
        root = addHelper(root, data);
    }

    public int minimum(BSTNode node){
        while(node.left != null){
            node = node.left;
        }
        return node.data;
    }

    private BSTNode deleteHelper(BSTNode root, int data){
        if(root == null)
            return root;
        if(root.data > data)
            root.left = deleteHelper(root.left, data);
        else if(root.data < data)
            root.right = deleteHelper(root.right, data);
        else{
            if(root.right == null)
                return root.left;
            else if(root.left == null)
                return root.right;
            else{
                root.data = minimum(root.right);
                root.right = deleteHelper(root.right, root.data);
            }
        }
        return root;
    }

    public void delete(int data){
        root = deleteHelper(root, data);
    }

    private void inOrderHelper(BSTNode root){
        if(root == null)
            return;
        inOrderHelper(root.left);
        System.out.print(root.data + " ");
        inOrderHelper(root.right);
    }

    public void inOrder(){
        inOrderHelper(root);
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        BST bst = new BST();
        int i, data;
        boolean flag = true;
        System.out.println("1. Insert in BST");
        System.out.println("2. Delete in BST");
        System.out.println("3. Search in BST");
        System.out.println("4. Display in BST");
        System.out.println("5. Exit");
        while (flag){
            System.out.println("Enter your choice");
            i = in.nextInt();
            switch (i){
                case 1:
                    System.out.println("Enter a data value");
                    data = in.nextInt();
                    bst.add(data);
                    break;
                case 2:
                    System.out.println("Enter a data value");
                    data = in.nextInt();
                    bst.delete(data);
                    break;
                case 3:
                    System.out.println("Enter a data value");
                    data = in.nextInt();
                    if(bst.search(data))
                        System.out.println("Data " + data + " Found");
                    else
                        System.out.println("Data " + data + " Not Found");
                    break;
                case 4:
                    bst.inOrder();
                    break;
                case 5:
                    flag = false;
                    break;
                default:
                    System.out.println("Wrong Choice");
            }
        }
    }
}