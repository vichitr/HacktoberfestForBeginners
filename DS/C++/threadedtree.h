/***************************************************

Notes:
This an implementation of threaded tree in C++
Threaded tree is a binary search tree that allows for easier in-order traversal
For each node, all right/ left child pointers that would normally be null instead point to the in-order successor node
This implementation supports generic typing and both forward and backward in-order traversal, but does not handle duplicate values

Const and non-const iterator implementation also included to facilitate easy traversal via operators

***************************************************/

#include <iostream>
using namespace std;

// Generic type threaded tree
template <class T>
class ThreadedTree {
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int lFlag_;		// Whether the node has a left thread, 0 = no, 1 = yes
		int rFlag_;		// Whether the node has a right thread, 0 = no, 1 = yes

		Node(const T& data, Node* lt = nullptr, Node* rt = nullptr, int lFlag = 0, int rFlag = 0) {
			data_ = data;
			left_ = lt;
			right_ = rt;
			lFlag_ = lFlag;
			rFlag_ = rFlag;
		}
	};
	Node* root_;

public:
    // Const iterator member
	class const_iterator{
	private:
		const ThreadedTree* myTree_;
		Node* curr_;

		// Private constructor
		const_iterator(Node* curr, const ThreadedTree* theTree) {
			curr_ = curr;
			myTree_ = theTree;
		}

	public:
		// Constructor
		const_iterator(){
			myTree_ = nullptr;
			curr_ = nullptr;
		}

		// Postfix ++ increments iterator and returns old value
		// @return: iterator containing old value
		const_iterator operator++(int){
			const_iterator old = *this;

			// If the current node has a right thread, we use that to move forward
			if (curr_->rFlag_ == 1) {
				curr_ = curr_->right_;
			}
			// If it doesn't have a right thread, we need to move to the left-most node in its right subtree
			// However we only move forward if the right node isn't nullptr (i.e. we're at max value already)
			else {
				curr_ = curr_->right_;

				if (curr_ != nullptr) {
					while (curr_->left_ != nullptr && curr_->lFlag_ != 1) {
						curr_ = curr_->left_;
					}
				}
			}

			//Return the old node
			return old;
		}

		// Postfix -- decrements iterator and returns old value
		// @return: iterator containing old value
		const_iterator operator--(int){
			const_iterator old = *this;

			// If the current node is nullptr, we're at end, move back to actual last value
			// Could also implement an end sentinel, which would be more robust, but I don't want to risk breaking the tester
			if (curr_ == nullptr) {
				if (myTree_->root_ != nullptr) {
					curr_ = myTree_->root_;
					while (curr_->right_ != nullptr) {
						curr_ = curr_->right_;
					}
				}
			}
			else {
				// If the current node has a left thread, we use that to move backwards
				if (curr_->lFlag_ == 1) {
					curr_ = curr_->left_;
				}
				// If it doesn't have a left thread, we need to move to the right-most node in its left subtree
				// However we only move backward if the left node isn't nullptr (i.e. we're at least value already)
				else if (curr_->left_ != nullptr) {
					curr_ = curr_->left_;

					while (curr_->right_ != nullptr && curr_->rFlag_ != 1) {
						curr_ = curr_->right_;
					}
				}
			}
			//Return the old node
			return old;
		}

		// Prefix ++ increments iterator and returns new value
		// @return: iterator containing new value
		const_iterator operator++(){
			// If the current node has a right thread, we use that to move forward
			if (curr_->rFlag_ == 1) {
				curr_ = curr_->right_;
			}
			// If it doesn't have a right thread, we need to move to the left-most node in its right subtree
			// However we only move forward if the right node isn't nullptr (i.e. we're at max value already)
			else {
				curr_ = curr_->right_;

				if (curr_ != nullptr) {
					while (curr_->left_ != nullptr && curr_->lFlag_ != 1) {
						curr_ = curr_->left_;
					}
				}
			}

			//Return the new node
			return *this;
		}

		// Prefix -- decrements iterator and returns new value
		// @return: iterator containing new value
		const_iterator operator--(){
			// If the current node is nullptr, we're at end, move back to actual last value
			if (this->curr_ == nullptr) {
				if (myTree_->root_ != nullptr) {
					curr_ = myTree_->root_;
					while (curr_->right_ != nullptr) {
						curr_ = curr_->right_;
					}
				}
			}
			else {
				// If the current node has a left thread, we use that to move backwards
				if (curr_->lFlag_ == 1) {
					curr_ = curr_->left_;
				}
				// If it doesn't have a left thread, we need to move to the right-most node in its left subtree
				// However we only move backward if the left node isn't nullptr (i.e. we're at least value already)
				else if (curr_->left_ != nullptr) {
					curr_ = curr_->left_;

					while (curr_->right_ != nullptr && curr_->rFlag_ != 1) {
						curr_ = curr_->right_;
					}
				}
			}
			//Return the new node
			return *this;
		}

		// Dereference operator returns the data value stored in the current node
		// @return: current node's data value
		const T& operator*() const{
			return curr_->data_;
		}

		// Returns whether or not the current iterator is the same as the rhs iterator
		// @return: True/ False if the iterators are the same
		bool operator==(const const_iterator& rhs) const{
			bool ret = false;

			//Test if RHS both the same node and in the same ThreadedTree
			if (myTree_ == rhs.myTree_ && curr_ == rhs.curr_) {
				ret = true;
			}

			return ret;
		}

		// Returns whether or not the current iterator is NOT the same as the rhs iterator
		// @return: True/ False if the iterators are NOT the same
		bool operator!=(const const_iterator& rhs) const{
			bool ret = false;

			//Test if either RHS is not in the same tree, or in the same tree but not the same node
			if (myTree_ != rhs.myTree_ || curr_ != rhs.curr_) {
				ret = true;
			}

			return ret;
		}

		friend class ThreadedTree; // Make friend to access threaded tree members
	};

    // Non-const iterator member
    class iterator:public const_iterator{
	private:
		//Private constructor calls the constant iterator's private constructor
		iterator(Node* curr, ThreadedTree* theTree) :const_iterator(curr, theTree) {}

	public:
		iterator():const_iterator(){}

		const T& operator*() const{
			return this->curr_->data_;
		}

		T& operator*(){
			return this->curr_->data_;
		}	

		iterator operator++(int){
			iterator old = *this;

			// If the current node has a right thread, we use that to move forward
			if (this->curr_->rFlag_ == 1) {
				this->curr_ = this->curr_->right_;
			}
			// If it doesn't have a right thread, we need to move to the left-most node in its right subtree
			// However we only move forward if the right node isn't nullptr (i.e. we're at max value already)
			else {
				this->curr_ = this->curr_->right_;

				if (this->curr_ != nullptr) {
					while (this->curr_->left_ != nullptr && this->curr_->lFlag_ != 1) {
						this->curr_ = this->curr_->left_;
					}
				}
			}

			//Return the old node
			return old;
		}

		iterator operator--(int){
			iterator old = *this;

			// If the current node is nullptr, we're at end, move back to actual last value
			if (this->curr_ == nullptr) {
				if (this->myTree_->root_ != nullptr) {
					this->curr_ = this->myTree_->root_;
					while (this->curr_->right_ != nullptr) {
						this->curr_ = this->curr_->right_;
					}
				}
			}
			else {
				// If the current node has a left thread, we use that to move backwards
				if (this->curr_->lFlag_ == 1) {
					this->curr_ = this->curr_->left_;
				}
				// If it doesn't have a left thread, we need to move to the right-most node in its left subtree
				// However we only move backward if the left node isn't nullptr (i.e. we're at least value already)
				else if (this->curr_->left_ != nullptr) {
					this->curr_ = this->curr_->left_;

					while (this->curr_->right_ != nullptr && this->curr_->rFlag_ != 1) {
						this->curr_ = this->curr_->right_;
					}
				}
			}
			//Return the old node
			return old;
		}

		iterator operator++(){
			// If the current node has a right thread, we use that to move forward
			if (this->curr_->rFlag_ == 1) {
				this->curr_ = this->curr_->right_;
			}
			// If it doesn't have a right thread, we need to move to the left-most node in its right subtree
			// However we only move forward if the right node isn't nullptr (i.e. we're at max value already)
			else {
				this->curr_ = this->curr_->right_;

				if (this->curr_ != nullptr) {
					while (this->curr_->left_ != nullptr && this->curr_->lFlag_ != 1) {
						this->curr_ = this->curr_->left_;
					}
				}
			}

			//Return the new node
			return *this;
		}

		iterator operator--(){
			// If the current node is nullptr, we're at end, move back to actual last value
			if (this->curr_ == nullptr) {
				if (this->myTree_->root_ != nullptr) {
					this->curr_ = this->myTree_->root_;
					while (this->curr_->right_ != nullptr) {
						this->curr_ = this->curr_->right_;
					}
				}
			}
			else {
				// If the current node has a left thread, we use that to move backwards
				if (this->curr_->lFlag_ == 1) {
					this->curr_ = this->curr_->left_;
				}
				// If it doesn't have a left thread, we need to move to the right-most node in its left subtree
				// However we only move backward if the left node isn't nullptr (i.e. we're at least value already)
				else if (this->curr_->left_ != nullptr) {
					this->curr_ = this->curr_->left_;

					while (this->curr_->right_ != nullptr && this->curr_->rFlag_ != 1) {
						this->curr_ = this->curr_->right_;
					}
				}
			}

			//Return the new node
			return *this;
		}

		friend class ThreadedTree; // Make friend to access threaded tree members
	};

	// Default constructor, sets root node to nullptr
	ThreadedTree(){
		root_ = nullptr;
	}

	// Inserts a new value into the tree
	// @params data: the data value to insert
	void insert(const T& data){

		if (root_ == nullptr) {
			root_ = new Node(data);
		}
		else {
			recursiveInsert(root_, data);
		}
	}

	// Helper function that recursively searches for the correct place to insert a node
	// @params node: the current node being inspected while looking for insertion location
	// @params parent: the inspected node's immediate parent node
	// @params data: the data value to insert
	// @return: returns the node modified by the insert (when called recurisely, this chains all the way up to the root)
	void recursiveInsert(Node* node, const T& data) {
		// If the data is less than the current node's, inspect to the left
		if (data < node->data_) {
			// If the left node is free, we can add the new node as its left child
			if (node->left_ == nullptr || node->lFlag_ == 1) {
				Node* ins = new Node(data);

				// Since we are inserting to the left, the new child inherits the current node's left pointer
				ins->left_ = node->left_;
				// Also need to set the left thread flag of the child if it's not nullptr (i.e. if child is not the least value in the tree)
				if (ins->left_ != nullptr) {
					ins->lFlag_ = 1;
				}

				// The child's right pointer then becomes a thread to the node (iteratively, the parent always comes after left child)
				ins->rFlag_ = 1;
				ins->right_ = node;

				// Clear the node's left thread flag and point its left to the newly added child
				node->lFlag_ = 0;
				node->left_ = ins;

				// Null the temporary pointer to avoid errors when going out of scope
				ins = nullptr;
			}
			// If it isn't free, keep inspecting
			else {
				recursiveInsert(node->left_, data);
			}
		}
		// If the data is greater than the current node's, inspect to the right
		else if (data > node->data_) {
			// If the right node is free, we can add the new node as its left child
			if (node->right_ == nullptr || node->rFlag_ == 1) {
				Node* ins = new Node(data);

				// Since we are inserting to the right, the new child inherits the current node's right pointer
				ins->right_ = node->right_;
				// Also need to set the right thread flag of the child if it's not nullptr (i.e. if child is not the most value in the tree)
				if (ins->right_ != nullptr) {
					ins->rFlag_ = 1;
				}

				// The child's left pointer then becomes a thread to the node (iteratively, the parent always comes after left child)
				ins->lFlag_ = 1;
				ins->left_ = node;

				// Clear the node's right thread flag and point its right to the newly added child
				node->rFlag_ = 0;
				node->right_ = ins;

				// Null the temporary pointer to avoid errors when going out of scope
				ins = nullptr;
			}
			// If it isn't free, keep inspecting
			else {
				recursiveInsert(node->right_, data);
			}
		}

		// Note: We have to assume that there are no duplicate values as this implementation does not support them
	}
};