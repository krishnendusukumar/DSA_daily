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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, TreeNode*>m;
        q.push(root);
        while(q.size()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left) {
                m[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                m[node->right] = node;
                q.push(node->right);
            }
        }
        
        // till yet we have marked the parents of the node
        
        q.push(target);
        
        unordered_map<TreeNode*, int> visited;
        visited[target] = 1;
        
        while(q.size() && k--) {
            int size = q.size();
            
            for(int i=0;i < size; i++) {
                 TreeNode* node = q.front(); q.pop();
                if(node->left && visited[node->left] == 0) {
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && visited[node->right] == 0) {
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                if(m[node] && visited[m[node]] == 0) {
                    visited[m[node]] = 1;
                    q.push(m[node]);
                }
            }
        }
        
        
        vector<int> ans;
        while(q.size()) {
            TreeNode* temp = q.front(); q.pop();
            ans.push_back(temp->val);
        }
        return ans;
        
        
        
    }
};