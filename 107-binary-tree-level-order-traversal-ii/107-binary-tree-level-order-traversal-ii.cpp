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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
          queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root == nullptr) return v;
        q.push(root);
        while(q.size()>0){
            vector<int> v1;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* head = q.front();
                q.pop();
                if(head->left!=nullptr) q.push(head->left);
            if(head->right!=nullptr) q.push(head->right);
            v1.push_back({head->val});
        }
            v.push_back(v1);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};