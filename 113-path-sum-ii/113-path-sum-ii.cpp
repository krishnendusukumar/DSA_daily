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
    
    void helper(TreeNode *root, vector<vector<int>>& ans, int sum, vector<int> temp) {
        if((root == nullptr) || (root->left == nullptr && root->right == nullptr)) {
            if(root == nullptr) return;
            if(sum == (root->val)) {
                temp.push_back(root->val);
                ans.push_back(temp);}
            return;
        }
        
        temp.push_back(root->val);
            helper(root->left, ans, sum-(root->val), temp);
            helper(root->right, ans, sum - (root->val), temp);
        temp.pop_back();
        return;
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root, ans, tar, temp);
        return ans;
    }
};