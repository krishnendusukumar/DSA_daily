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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefix = 0;
        unordered_map<int, ListNode*> m;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        for(auto i = dummy; i != nullptr; i= i-> next) {
            prefix += i->val;
            m[prefix] = i;
        }
        prefix = 0;
        for(auto i = dummy; i != nullptr; i = i -> next) {
            i->next = m[prefix += i->val]->next;
        }
        return dummy->next;
    }
};