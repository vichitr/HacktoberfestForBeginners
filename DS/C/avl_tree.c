# include <stdio.h>
# include <stdlib.h>

#define clear() printf("\033[H\033[J")

typedef struct _node{
	int key;
	int height, level;
	int right_height, left_height;
	struct _node *left;
	struct _node *right;
	struct _node *root_node;
} Node;

typedef struct _tree{
	Node *root;
} Tree;

Tree *init_tree(){
	Tree *tree = (Tree*)malloc(sizeof(Tree));
	tree->root=NULL;
	return tree;
}

void show_menu();
void show_tree(Node *root);
Node * normal_insert(Node *root_node, int value);
Node * search_insert_element(Node *root, int value);
Node * verify_weight(Node *added_node);
Node * right_rotate(Node *root_node);
Node * left_rotate(Node *root_node);
void new_tree_height(Node *sub_tree);
int height_calc(Node *sub_tree);

int main(){
	Tree *test = init_tree();
	
	int value;
	int option=-1;
	do{
		show_menu();
		scanf("%d", &option);
		switch(option){
			case 0:
				exit(0);
			case 1:
				clear();
				printf("\nInsert value: ");
				scanf("%d", &value);
				if(test->root == NULL)
					test->root = normal_insert(test->root,value);
				else
					test->root = search_insert_element(test->root,value);
				break;
			case 2:
				clear();
				printf ("\nTree elements:\n");
				show_tree(test->root);
				getchar();
				getchar();
				break;
			default:
				clear();
				printf("Invalid\n");
		}
	}while(1);
}

void show_menu(){
	printf("\nAVL Tree\n");
	printf("Choose an option\n");
	printf("0 - Exit\n");
	printf("1 - Insert Element\n");
	printf("2 - List Elements\n");
	printf("\nOption: ");
}

Node *normal_insert(Node *root_node, int value){
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->root_node = root_node;
	new_node->key = value;
	new_node->height = 0;
	new_node->right_height = 0;
	new_node->left_height = 0;

	return new_node;
}

Node * search_insert_element(Node *root, int value){
	if(root == NULL)
		return root;
	
	if(value > root->key){
		root->right_height++;
		root->level = root->left_height - root->right_height;
		if(root->right == NULL){
			root->right = normal_insert(root,value);
			new_tree_height(root->right);
			root = verify_weight(root->right);
		}else
			root = search_insert_element(root->right,value);

	}else if(value < root->key){
		root->left_height++;
		root->level = root->left_height - root->right_height;
		if(root->left == NULL){
			root->left = normal_insert(root,value);
			new_tree_height(root->left);
			root = verify_weight(root->left);
		}else
			root = search_insert_element(root->left,value);
	}else{	
		printf("Already inserted");
	}
	if(root->left_height>=root->right_height)
		root->height = root->left_height;
	else
		root->height = root->right_height;

}


Node * verify_weight(Node *added_node){
	Node *root_node = added_node->root_node;
	Node *root_root_node = root_node->root_node;

	new_tree_height(added_node);

	while(root_root_node != NULL){
		if(root_root_node->level < -1 && root_node->level < 0){
			root_node = left_rotate(root_root_node);
			break;
		}else if(root_root_node->level > 1 && root_node->level > 0){
			root_node = right_rotate(root_root_node);
			break;
		}else if(root_root_node->level< -1 && root_node->level > 0){
			root_node = right_rotate(root_node);
			root_root_node = left_rotate(root_root_node);
			break;
		}else if(root_root_node->level > 1 && root_node->level < 0){
			root_node = left_rotate(root_node);
			root_root_node = right_rotate(root_root_node);
			break;
		}

		root_root_node = root_root_node->root_node;
		root_node = root_node->root_node;
	}
	while(root_node->root_node != NULL)
		root_node = root_node->root_node;

	return root_node;
}

void show_tree(Node *root){
	if(root == NULL)
		return;
	
	show_tree(root->left);
	if(root->root_node == NULL)
		printf("\nKey: %d || Left Height: %d || Right Height: %d || Height: %d || Level: %d || Root: %s", root->key, root->left_height, root->right_height, root->height, root->level, "Raiz");
	else
		printf("\nKey: %d || Left Height: %d || Right Height: %d || Height: %d || Level: %d || Root: %d", root->key, root->left_height, root->right_height, root->height, root->level, root->root_node->key);
	show_tree(root->right);
}


Node * left_rotate(Node *root){	
	Node *node_son = root->right;
    	root->right = node_son->left;

    	if ( node_son->left != NULL )
        	node_son->left->root_node = root;
    	node_son->left = root;
   	node_son->root_node = root->root_node;
    	if ( root->root_node != NULL )
        	if ( root->root_node->left == root )
            		root->root_node->left = node_son;
        	else
            		root->root_node->right = node_son;
    	root->root_node = node_son;
	
	new_tree_height(node_son->right);
	new_tree_height(node_son->left);
	return node_son;
}

Node * right_rotate(Node *root){
	Node *node_son = root->left;

    	root->left = node_son->right;
    	if ( node_son->right != NULL )
        	node_son->right->root_node = root;
    	node_son->right = root;
    	node_son->root_node = root->root_node;
    	if ( root->root_node != NULL )
        	if ( root->root_node->left == root )
            		root->root_node->left = node_son;
        	else
            		root->root_node->right = node_son;
    	root->root_node = node_son;

	new_tree_height(node_son->right);
	new_tree_height(node_son->left);
	return node_son;
}

void new_tree_height(Node *node_son){
	if(node_son == NULL)
		return;

	node_son->right_height = height_calc(node_son->right);
	node_son->left_height = height_calc(node_son->left);
	if(node_son->left_height >= node_son->right_height)
		node_son->height = node_son->left_height;
	else
		node_son->height = node_son->right_height;

	node_son->level = node_son->left_height - node_son->right_height;
	new_tree_height(node_son->root_node);
}

int height_calc(Node *sub_tree){
	if(sub_tree == NULL)
		return 0;

	int t_left_height;
	int t_right_height;

	t_left_height = height_calc(sub_tree->left);
	t_right_height = height_calc(sub_tree->right);

	if(t_left_height>=t_right_height)
		return t_left_height+1;
	else
		return t_right_height+1;
}
