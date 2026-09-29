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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev = dummy;
        while(true)
        {
            ListNode* groupNext = groupPrev;
            for(int i=0;i<k;i++){
                groupNext= groupNext->next;
                if(!groupNext){ // no k elements remain
                    return dummy->next;
                }
            }

            ListNode* nextGroup = groupNext->next; // point to next group starting node 
            ListNode* prev = nextGroup; // prev pointed to next element so that we link this after reverse
            ListNode* curr = groupPrev->next;
            for(int i = 0;i<k;i++){
                
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr=nxt;
            }
            ListNode* oldPrevHead = groupPrev->next;
            groupPrev->next = groupNext;
            groupPrev = oldPrevHead;

        }
        return dummy->next;
    }
};
