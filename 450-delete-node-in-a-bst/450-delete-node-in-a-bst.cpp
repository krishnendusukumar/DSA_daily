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
    
    TreeNode* helper(TreeNode* root) {
        if(root->left == nullptr) return root->right;
        if(root->right == nullptr) return root->left;
        
        TreeNode* cur = root->right;
        TreeNode* prev = find(root->left);
        prev->right = cur;
        return root->left;
    } 
    TreeNode* find(TreeNode* root) {
        if(root->right == nullptr) return root;
        return find(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root -> val == key) return helper(root);
        TreeNode *prev = root;
        while(root) {
            if(root->val > key){
                if(root ->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else {
                if(root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else root =root->right;
            }
        }
        return prev;
        
    }
};