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
    
    void helper(TreeNode* root,int& maxi, bool flag) {
        if(flag == true && !root->right && !root->left) {maxi += root->val;return;}
        if(root->left != nullptr) helper(root->left, maxi, true);
        if(root->right != nullptr) helper(root->right, maxi, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxi = 0;
        helper(root, maxi, false);
        return maxi;
    }
};