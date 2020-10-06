// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        if(root == NULL) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto top = q.front();
            int level = top.second;
            TreeNode* curr = top.first;
            
            if(output.size() > level) output[level].push_back(curr->val);
            else output.push_back({curr->val});
            
            q.pop();
            if(curr->left)
                q.push({curr->left, level+1});
            
            if(curr->right)
                q.push({curr->right, level+1});
        }
        return output;
    }
};