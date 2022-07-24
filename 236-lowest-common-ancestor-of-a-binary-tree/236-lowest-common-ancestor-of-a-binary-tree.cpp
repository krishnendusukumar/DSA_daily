/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool helper(TreeNode* root, TreeNode* i, vector<TreeNode*>& ans) {
        if(root == nullptr) return false;
        
        ans.push_back(root);
        if(root == i) return true;
        
        if(helper(root->left, i, ans) || helper(root->right, i, ans)) return true;
        
        ans.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> res, temp;
        
        helper(root, p, res);
        helper(root, q, temp);
        
        TreeNode* ans = res[0];
        for(int i = 0; i < temp.size() && i < res.size(); i++) {
            if(res[i] == temp[i]) ans = res[i];
            else return ans;
        }
        return ans;
    }
};