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
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *ans, *tail;
        if(l1->val < l2->val) 
        {
            ans = l1;
            tail = l1;
            l1 =  l1->next;  
        }
        else {
            ans = l2;
            tail = l2;
            l2  = l2->next;  
        } 

        while(l1 != NULL && l2 != NULL)
    {
        // If value pointed by l1 is smaller than l2's value

        if(l1 -> val < l2 -> val)
        {
            // We make Tail's Next point to l1

            tail -> next = l1 ;

            // We move tail to l1

            tail = l1 ;

            // l1  moves to it's Next Node

            l1 = l1 -> next ;
        }

        // Otherwise, value pointed by l2 is smaller than or equal to l1's value

        else
        {
            // We make Tail's Next point to l2

            tail -> next = l2 ;

            // We move tail to l2

            tail = l2 ;

            // l2 moves to it's Next Node

            l2 = l2 -> next ;

        }
    }

        if (l1 == nullptr) {
            tail -> next = l2;
        }
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