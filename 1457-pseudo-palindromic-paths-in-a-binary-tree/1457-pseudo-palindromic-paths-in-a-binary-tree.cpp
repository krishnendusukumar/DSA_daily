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
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> store_num(9,0);
        helper(root, store_num);
        return res;
    }
    
    void helper(TreeNode* root, vector<int> store_num){
        store_num[root->val - 1]++;
        
        if(root->left != nullptr) helper(root->left, store_num);
        if(root->right) helper(root->right, store_num);
        if(!root->left && !root->right) {
            int ct=0;
            for(int i=0;i<9;i++) {
                if(store_num[i]%2!=0) ct++;
            }
            if(ct<=1) res++;
        }
    }
};