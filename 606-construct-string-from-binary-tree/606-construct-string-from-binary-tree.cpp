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
    
    string helper(TreeNode* root) {
        if(root == nullptr) return "";
        
        string roott = to_string(root->val);
        string leftt = helper(root->left);
        string rightt = helper(root->right);
        
        
        if(rightt != "") {
            roott += "(";
                roott += leftt;
                roott += ")";
                roott += "(";
                roott += rightt;
                roott += ")";
        }
        else {
            if(leftt != "") {
                roott += "(";
                roott += leftt;
                roott += ")";
            }
        }
        return roott;
        
    }
    
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};