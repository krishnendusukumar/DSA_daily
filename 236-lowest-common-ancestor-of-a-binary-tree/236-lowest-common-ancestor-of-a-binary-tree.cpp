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
    
    bool helper(TreeNode* root, TreeNode* p, vector<int>& ans) {
        if(root == nullptr) return false;
        
        ans.push_back(root -> val);
        if(root == p) return true;
        
        if(helper(root -> left, p, ans) || helper(root->right, p, ans)) return true;
        
        ans.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> ans, temp;
    
        helper(root, p, ans);
        helper(root, q, temp);
        
        TreeNode* res = new TreeNode(ans[0]);
        for(int i= 0; i < ans.size() && i < temp.size(); i++) {
            if(ans[i] == temp[i]) res->val = ans[i];
            else return res;
        }
        return res;
    }
};