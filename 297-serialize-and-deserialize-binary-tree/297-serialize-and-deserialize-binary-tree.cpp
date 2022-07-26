/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    
    
    // Encodes a tree to a single string.
//      if(!root) return "";
        
//         string s ="";
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()) {
//            TreeNode* curNode = q.front();
//            q.pop();
//            if(curNode==NULL) s.append("#,");
//            else s.append(to_string(curNode->val)+',');
//            if(curNode != NULL){
//                q.push(curNode->left);
//                q.push(curNode->right);            
//            }
//         }
//         return s;
    
    
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr) return "";
        string s = "";
        q.push(root);
        while(q.size()) {
                TreeNode* node = q.front(); q.pop();
                if(node == nullptr) {
                    s.append("#,");
                }
                else {
                    s.append(to_string(node->val)+',');
                }
                if(node != nullptr) {
                    q.push(node->left);
                    q.push(node->right);
                }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        if(data.size() == 0) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(q.size()) {
            TreeNode* temp = q.front();  q.pop();
            getline(s, str, ',');
            if(str == "#") temp->left = nullptr;
            else {
                TreeNode* cur = new TreeNode(stoi(str));
                temp->left = cur;
                q.push(cur);
            }
            
            getline(s, str, ',');
            if(str == "#") temp->right = nullptr;
            else {
                TreeNode* curr = new TreeNode(stoi(str));
                temp->right = curr;
                q.push(curr);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));