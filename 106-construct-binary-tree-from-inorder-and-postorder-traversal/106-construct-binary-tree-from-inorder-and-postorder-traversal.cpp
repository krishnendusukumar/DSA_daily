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
    
    TreeNode* buildT(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, map<int,int>& m) {
        
        if(poststart > postend || instart > inend) return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postend]);
        
        int inroot = m[postorder[postend]];
        int gap = inroot - instart;
        
        
        root -> left = buildT(inorder, instart, inroot - 1, postorder, poststart, poststart + gap - 1, m);
        root ->right = buildT(inorder, inroot + 1, inend, postorder, poststart + gap, postend - 1, m);
        
        return root;
    }
    
    
     
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;
        
        map<int,int> m;
        for(int i = 0; i < inorder.size(); i++) m[inorder[i]] = i;
        
        return buildT(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, m);
        
    }
};