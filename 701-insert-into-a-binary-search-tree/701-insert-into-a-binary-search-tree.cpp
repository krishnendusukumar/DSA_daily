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
    
    TreeNode* helper(TreeNode* root, int val) {
        if(root -> val > val && root->left == nullptr) {
            root ->left = new TreeNode(val);
            return root;
        }
        if(root -> val < val && root->right == nullptr) {
            root ->right = new TreeNode(val);
            return root;
        }
        else if(root ->val > val) return helper(root->left, val);
        else return helper(root->right, val);
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            TreeNode *res = new TreeNode(val);
            return res;
        }
    helper(root, val);
        return root;
    }
};