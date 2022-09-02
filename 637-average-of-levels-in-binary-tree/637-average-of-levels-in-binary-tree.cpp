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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(root->val);
        while(q.size()){
            int size = q.size();
        double res = 0;
            int count = 0;
            for(int i = 0 ; i < size; i++) {
            TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {q.push(curr->left);
                                count++;
                               res += curr->left->val;}
                if(curr->right) {q.push(curr->right);
                                 count++;
                                res += curr->right->val;}
            }
            if(count > 0) v.push_back(res / count);
        }
        return v;
    }
};

//  3 1 5 0 2 4 6
     
//      3  
//     1 5
//    0 2 4 6