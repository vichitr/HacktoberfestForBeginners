/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        // stop recursion if root is null
        if (root == NULL) {
            return NULL;
        }
        // recursively travel to the left and right node
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        // swap the left and right children of the node
        swap(root->left, root->right);

        // return the current root
        return root;
    }
};