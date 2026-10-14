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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*t = new ListNode();
        ListNode* s = t;
        ListNode*h1 = list1, *h2 = list2;
        while(h1 && h2){
            if(h1->val <= h2->val){
                t->next= h1;
                h1=h1->next;
            }
            else{
                t->next= h2;
                h2=h2->next;
            }
            t=t->next;
        }
        if(h2){
            t->next = h2;
        }
        if(h1){
            t->next=h1;
        }
        return s->next;
    }
};
