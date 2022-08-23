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
    
    
    ListNode* rev(ListNode* head) {
        ListNode* curr, *prev = nullptr, *forw;
        
        curr = head;
        
        while(curr) {
           forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr) return false;
        
        ListNode* slow , *fast;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = slow;
        slow = rev(slow->next);
        
        while(slow) {
            if(head->val != slow->val) return false;
            head= head->next;
            slow = slow->next;
        }
        return true;
    }
};