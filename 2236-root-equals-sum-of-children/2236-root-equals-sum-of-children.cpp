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
    
    
    int helper(TreeNode* root) {
        if((root ->left == NULL && root->right == NULL)) return root->val;
        
        int left = helper(root->left);
        int right = helper(root->right);
        
        return left + right;
    }
    
    bool checkTree(TreeNode* root) {
        if(helper(root) == root->val) return true;
        return false;
    }
};