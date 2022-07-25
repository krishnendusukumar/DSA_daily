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
 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        
        vector<int> ans;
       TreeNode* root = buildT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1, m);
        
        return root;
    }
    
    
//     if(preStart>preEnd || inStart>inEnd) return NULL;
//         TreeNode *root = new TreeNode(preorder[preStart]);
        
//         int inRoot = mp[root->val];
//         int numsleft = inRoot - inStart;
        
//         root->left =buildTree(preorder,preStart+1,preStart+numsleft,inorder,inStart,inRoot-1,mp);
//         root->right =buildTree(preorder,preStart+numsleft+1,preEnd,inorder,inRoot+1,inEnd,mp);
    
    
    TreeNode* buildT(vector<int> preorder, int prestart, int prend, vector<int> inorder, int instart, int inend, map<int, int>& m) {
        if(prestart > prend) return NULL;
        
        TreeNode* root = new TreeNode (preorder[prestart]);
        
        int inroot = m[preorder[prestart]];
        int gap = inroot - instart;
        root->left = buildT(preorder, prestart + 1, prestart + gap, inorder, instart, inroot - 1, m);
        root -> right = buildT(preorder, prestart + gap + 1, prend, inorder, inroot + 1, inend, m);
        
        return root;
    }
};