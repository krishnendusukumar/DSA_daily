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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        bool flag = true;
        while(q.size() > 0) {
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i < size; i++) {
                TreeNode* head = q.front();
                q.pop();
                int index = flag ? i : (size - 1 - i);
                temp[index] = head->val;
                    if(head->left) q.push(head->left);
                    if(head->right) q.push(head->right);
            }
            flag = !flag;
            ans.push_back(temp);
        }
        return ans;
    }
};