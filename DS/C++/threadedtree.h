/***************************************************

Notes:
This an implementation of threaded tree in C++
Threaded tree is a binary search tree that allows for easier in-order traversal
For each node, all right/ left child pointers that would normally be null instead point to the in-order successor node
This implementation supports generic typing and both forward and backward in-order traversal, but does not handle duplicate values

Iterator implementation also included to facilitate easy traversal via operators

***************************************************/