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
    void reorderList(ListNode* head) {
        ListNode* s = head, *f = head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        ListNode* first = head;
        ListNode* prev = nullptr, *curr = s->next, *nxt = nullptr;
        s->next = nullptr;
        while(curr){
            nxt = curr->next;
            curr->next=prev;
            prev = curr;
            curr = nxt;

        }
        ListNode* second = prev;
        ListNode*t = new ListNode();

        while(first && second){
            ListNode* nextF = first->next;
            ListNode* nextS = second->next;
            t->next = first;
            first->next=second;
            t=second;
            first = nextF;
            second = nextS;
        }
        t->next = first;
    }
};
