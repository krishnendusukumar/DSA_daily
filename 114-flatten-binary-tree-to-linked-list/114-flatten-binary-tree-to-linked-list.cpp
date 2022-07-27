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
    void flatten(TreeNode* root) {
        TreeNode *curr = root;
        if(root == nullptr) return;
        while(curr) {
            if(curr ->left != nullptr){
            TreeNode *prev = curr->left;
            while(prev->right) prev = prev->right;
            prev->right = curr->right;
            curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr ->right;
        }
    }
};



//  if (!root) {
//         return;
//     }
    
//     TreeNode* curr = root;
//     while (curr != NULL) {
//         if (curr->left) {
//             TreeNode* prev = curr->left;
//             while (prev->right) {
//                 prev = prev->right;
//             }
//             prev->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//         }
//         curr = curr->right;

// //        1
// //       / \
// //      2   3
// //     / \   \ 
// //    4   6    5
// //            / \
// //           7    6
           
           
// //            1 
           
// //            1 2 4 6 3 5 7 6