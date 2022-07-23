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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({root, {0,0}});
        while(q.size()) {
                auto p = q.front();
                TreeNode* node = p.first;
                int x = p.second.first;
                int y = p.second.second;
                m[x][y].insert(node -> val);
                q.pop();
                if(node->left) {
                    q.push({node->left, {x-1, y+1}});
                }
                if(node->right) {
                    q.push({node->right, {x+1, y+1}});
                }
        }
        
        vector<vector<int>> res;
        for(auto i: m) {
            vector<int> ans;
            for(auto j:i.second) {
                ans.insert(ans.end(), j.second.begin(), j.second.end());
            }
            res.push_back(ans);
        }
        return res;
    }
};