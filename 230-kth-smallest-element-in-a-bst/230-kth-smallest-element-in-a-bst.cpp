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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        TreeNode* curr=root,*pre;
        while(curr){
            if(curr->left==NULL){
                k--;
                if(k==0) ans = curr->val;
                curr=curr->right;
            }else{
                pre=curr->left;
                while(pre->right && pre->right!=curr) pre=pre->right;
                if(!pre->right){
                    pre->right=curr;
                    curr=curr->left;
                }else{
                    pre->right=NULL;
                    k--;
                    if(k==0) ans = curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};