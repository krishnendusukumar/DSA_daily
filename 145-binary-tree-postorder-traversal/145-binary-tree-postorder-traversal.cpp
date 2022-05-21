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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> ans;
        if(root == nullptr) return ans;
        s1.push(root);
        TreeNode* node;
        while(!s1.empty()){
            node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left!=nullptr) s1.push(node->left);
            if(node->right!=nullptr) s1.push(node->right);
        }
        while(!s2.empty()){
            node = s2.top();
            ans.push_back(node->val);
            s2.pop();
        }
        return ans;
    }
};