/***************************************************

Notes:
This an implementation of threaded tree in C++
Threaded tree is a binary search tree that allows for easier in-order traversal
For each node, all right/ left child pointers that would normally be null instead point to the in-order successor node
This implementation supports generic typing and both forward and backward in-order traversal, but does not handle duplicate values

Iterator implementation also included to facilitate easy traversal via operators

***************************************************/

#include <iostream>
using namespace std;

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
};