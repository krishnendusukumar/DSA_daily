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
class Solution {
public:
    
    ListNode* addition(ListNode* l1, ListNode* l2) {
        ListNode *ans, *tail;
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        if(l1 -> val > l2->val) {
            ans = l2;
            tail = l2;
            l2 = l2 -> next;
        }
        else {
            ans = l1;
            tail = l1;
            l1 = l1->next;
        }
        
        while(l1 && l2) {
            if(l1 -> val > l2 -> val) {
                tail -> next = l2;
                tail = l2;
                l2 = l2->next;
            }
            else {
                tail -> next = l1;
                tail = l1;
                l1 = l1 -> next;
            }
        }
        if(l1 == nullptr) tail -> next = l2;
        else tail -> next = l1;
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode *add, *first;
        add = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            add = addition(add, lists[i]);
        }
        return add;
    }
};