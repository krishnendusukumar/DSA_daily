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
    void rev(ListNode* s, ListNode* e) {
     ListNode *prev=NULL;
        ListNode *curr=s;
        ListNode *forw=NULL;
        while(prev!=e){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
}
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 1) return head;
        int sum = k;
        ListNode* e = head , *dummy = new ListNode(-1), *beforeStart;
        dummy -> next = head;
        beforeStart = dummy;
        int i = 0;
        while(e != nullptr) {
            i++;
            if(i % k == 0) {
                ListNode* s = dummy->next, *temp = e -> next;
                rev(s, e);
                dummy->next = e;
                s->next = temp;
                dummy =  s;
                e = temp;
            }
            else {
                e = e->next;
            }
        }
        return beforeStart->next;
        
    }
};