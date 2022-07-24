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
    int widthOfBinaryTree(TreeNode* root) {
     int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(q.size()) {
            long long curr_id, last_id;
            long long size = q.size();
            long long min = q.front().second;
            for(int i= 0 ; i < size; i++) {
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long x = p.second - min;
                
                if(i == 0) curr_id = (x);
                if(i == size-1) last_id = x;
                 if(node->left) q.push({node->left, x*2 + 1});
            if(node->right) q.push({node->right, x*2 + 2});
            }
            long long y = last_id - curr_id + 1;
            if(ans < y) ans = y;
        }
        
        return ans;
    }
};
