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
        ListNode* end = head, *newHead, *start = head;
        while(sum != 1) {
            end = end->next;
            sum--;
            if(end == nullptr) return head;
        }
        newHead = reverseKGroup(end->next, k);
        rev(start, end);
        start -> next = newHead;
        
        return end;
        
    }
};