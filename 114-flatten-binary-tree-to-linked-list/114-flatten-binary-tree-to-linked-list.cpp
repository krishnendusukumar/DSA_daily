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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr = root;
        while(s.size()) {
            curr = s.top(); s.pop();
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
            if(s.size() > 0) curr -> right = s.top();
            curr->left = nullptr;
        }
    }
};