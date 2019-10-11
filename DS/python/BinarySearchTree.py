#Python Code for implementing Binary Search Tree, along with insertion, search and all three traversals in a tree.
#

class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 


def insert(root,node): 
    if root is None: 
        root = node 
    else: 
        if root.val < node.val: 
            if root.right is None: 
                root.right = node 
            else: 
                insert(root.right, node) 
        else: 
            if root.left is None: 
                root.left = node 
            else: 
                insert(root.left, node) 
def search(root,key): 
	if root is None or root.val == key: 
        return root 
    if root.val < key: 
        return search(root.right,key)     
    return search(root.left,key) 


def inorder(root): 
    if root: 
        inorder(root.left) 
        print(root.val) 
        inorder(root.right)     

def preorder(root) :
 if root:
  print(root.val)
  preorder(root.left)
  preorder(root.right)

def postorder(root):
 if root:
  postorder(root.left)
  postorder(root.right)
  print(root.val)


p=0
def main():
	
	print("Enter your choice to continue : ")
	print("1-Insert into tree ")
	print("2-Search in tree")
	print("3-Traverse the tree")
	choice=int(input("What do you want to do?"))
	if choice == 1 :
	    if p == 0 :
	    	val=int(input("Tree yet not created! Enter the first value to add into the tree : "))
	    	r=Node(val)
	    	p=p+1
	    else:  
	    	val=int(input("Enter the value you would like to insert : "))
	    	insert(r,Node(val))
		main()
	elif choice == 2 :
		if p==0 :
			print("Sorry! Tree yet not created!")
		else :	
			val=int(input("Enter the value you want to search for : "))
			search(r,val)
		main()
	elif choice == 3 :
		if p==0 :
			print("Sorry Tree yet not created!")
		else :
			print("Inorder Traversal : ")
            inorder(r)
            print("\n\nPreorder Traversal : ")
            preorder(r)
            print("\n\nPostorder Traversal : ")
            postorder(r) 
		main()
	else:
	 print("Please enter a valid choice")
	 main()
