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
        int leftHeight =max(0,helper(root->left, maxi));
        int rightHeight = max(0,helper(root->right, maxi));
        maxi = max(maxi, root->val + leftHeight + rightHeight) ;
        return root->val + max(leftHeight, rightHeight);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        helper(root, maxi);
        return maxi;
    }
};