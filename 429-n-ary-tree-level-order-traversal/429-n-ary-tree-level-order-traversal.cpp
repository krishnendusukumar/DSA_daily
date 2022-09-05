/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> v;
        while(q.size()) {
            vector<int> v1;
            int size = q.size();
            for(int i = 0 ; i < size; i++) {
            Node* temp = q.front(); q.pop();
            v1.push_back(temp->val);
            for(auto it: temp->children) q.push(it);
            }
            v.push_back(v1);
        }
        return v;
    }
};