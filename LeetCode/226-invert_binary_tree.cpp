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
        // stop if node doesn't exist
        if (root == NULL) {
            return NULL;
        }

        // recursively traverse the tree
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        //swap left and right children of node
        swap(root->left, root->right);

        return root;
    }
};