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
    
    int helper(TreeNode* root, int& maxi) {
        if(root == nullptr) return 0;
        
        int leftHeight = helper(root->left, maxi);
        int rightHeight = helper(root->right, maxi);
        maxi = max(maxi, leftHeight + rightHeight);
        return 1 + max(leftHeight , rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root,maxi);
        return maxi;
    }
};