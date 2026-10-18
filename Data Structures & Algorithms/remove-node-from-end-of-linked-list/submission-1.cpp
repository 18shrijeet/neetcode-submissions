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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        ListNode* temp = head;
        int c = 0;
        while(temp){c++;temp=temp->next;}

        ListNode* t = new ListNode();
        t->next = head;
        temp = t;
        for(int i=0;i<c-n;i++){
            temp = temp->next;
        }
        ListNode* tt = temp->next;
        temp->next = temp->next->next;
        delete(tt);

        return t->next;
    }
};
