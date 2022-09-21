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
    
    ListNode* reverse(ListNode *node) {
        ListNode *forw, *prev, *curr;
        curr = node;
        while(curr) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        
        ListNode *slow , *fast;
        slow = fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = reverse(slow->next);
        slow->next = nullptr;
        
        int maxi = -1;
        
        while(fast && temp) {
            maxi = max(maxi, fast->val + temp->val);
            fast = fast->next;
            temp = temp->next;
        }
        return maxi;
    }
};