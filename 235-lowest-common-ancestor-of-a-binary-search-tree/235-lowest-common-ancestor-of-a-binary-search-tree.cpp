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
    
    bool helper(TreeNode* root, vector<TreeNode*>& temp, TreeNode* p) {
        
        if(root == p) {
            temp.push_back(root);
            return true;
        }
        if(root == nullptr) return false;
        
        temp.push_back(root);
        if(helper(root->left, temp, p) || helper(root->right, temp, p)) return true;
        temp.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> temp, ans;
        helper(root, temp, p);
        helper(root, ans, q);
        
        if(ans.size() == 0 || temp.size() == 0) return nullptr;
        
        TreeNode* res = new TreeNode(ans[0]->val);
        for(auto i = 0; i < ans.size() && i < temp.size(); i++) {
            if(ans[i]->val != temp[i]->val) return res;
            else res = ans[i];
        }
        return res;
        
    }
};