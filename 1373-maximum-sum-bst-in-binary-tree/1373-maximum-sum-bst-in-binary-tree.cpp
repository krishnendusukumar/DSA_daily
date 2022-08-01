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
    
    
private: int ans = 0;
    public:
    
    tuple<int, int, int> getsum(TreeNode* root) {
        if(root == nullptr) return {INT_MAX, INT_MIN, 0};
        
        auto [left_min, left_max, left_sum] = getsum(root->left);
        auto [right_min, right_max, right_sum] = getsum(root->right);
        
        tuple<int, int, int> ret {INT_MIN, INT_MAX, 0};
        
        if(root->val >  left_max && root->val < right_min) {
            ret = {min(left_min, root->val), max(right_max, root->val), left_sum + right_sum + root->val};
            ans = max(ans, left_sum+right_sum+root->val);
        }
        return ret;
    }
    
    
    int maxSumBST(TreeNode* root) {
        getsum(root);
        return ans;
    }
};