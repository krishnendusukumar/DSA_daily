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
    
    bool helper(TreeNode* root) {
        if(root == nullptr) return false;
        
        
        bool left = helper(root->left);
        bool right = helper(root->right);
        
        if(left == 0) root->left = nullptr;
        if(right == 0) root->right = nullptr;
        
        if(root->val == 0) {
            return root->left || root->right;
        }
        else {
            return true;
        }
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
         helper(root);
        if(root->val == 0) {
            if(!root->left && !root->right) return nullptr;
            else return root;
        }
        return root;
    } 
};