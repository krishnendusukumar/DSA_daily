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
    
    void reverse(ListNode* start, ListNode* end) {
        ListNode* curr = start, *pre = nullptr, *forw = nullptr;
        
        while(pre != end) {
            forw = curr->next;
            curr-> next = pre;
            pre = curr;
            curr = forw;
        }
        return;
    }
    
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        int i = 0;
        ListNode* e = head, *dummy = new ListNode(-1);
        ListNode* beforeStart = dummy, *start;
        dummy ->next = head;
        ListNode *curr = new ListNode(-1);
        curr -> next = head;
        int j = 0;
        while(e != nullptr) {
            i++;
            if((i > j) && (i % (j+1) == 0)) {
                ListNode* s = dummy -> next, *temp = e->next;
                if(i % 2 == 1) {
                    dummy = e;
                    curr = e;
                    e = e->next;
                }
                else {reverse(s, e);
                dummy -> next = e;
                s->next = temp;
                e = temp;
                dummy = s;
                     curr = dummy;}
                j = i;
                i = 0;
            }
            else 
            {
                e = e->next;
                curr = curr -> next;
            }
        }
        if(i > 0) {
            if((i) % 2 == 0) {
                ListNode *s = dummy->next;
                reverse(s, curr);
                dummy -> next = curr;
                s->next = nullptr;
                dummy = s;
            }
        }
        
        return beforeStart->next;
        
        
    }
};