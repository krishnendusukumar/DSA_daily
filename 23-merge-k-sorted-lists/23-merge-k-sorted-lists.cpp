/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class cmp{
    public:
     bool operator() (ListNode *a, ListNode *b) {
        return (a->val > b-> val);
    }
};

class Solution {

    
    
    public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* ans, *dummy = new ListNode(-1);
        ans = dummy;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                q.push(lists[i]);
            }
        }
        while(q.size()) {
            ListNode *temp = q.top();
            q.pop();
            ans -> next = temp;
            ans = temp;
            if(temp->next) q.push(temp->next);
        }
        return dummy -> next;
    }
};