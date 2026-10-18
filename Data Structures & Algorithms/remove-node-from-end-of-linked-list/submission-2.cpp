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

/*
idea first move 1 pointer n steps , next move it and another pointer till end , so now first pointer moved total c steps , second moved ? c - n(initial) 

Two Pointers
Intuition
Use two pointers so that the gap between them is exactly n.
Move the right pointer n steps ahead first.
Then move both pointers together.
When the right pointer reaches the end, the left pointer will be just before the node we must remove.
This avoids a separate length-counting pass, while still traversing the list in O(N) time.
The key benefit is that the n-node gap tells us where to delete without storing nodes or computing the length first.
Algorithm
Create a dummy node pointing to the head (helps handle deletion of the first node).
Set two pointers:
left at dummy
right at head
Move right forward n steps.
Move both pointers until right reaches the end.
Now left.next is the node to delete → skip it by doing left.next = left.next.next.
Return dummy.next as the updated head.


*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = head;

        while (n > 0) {
            right = right->next;
            n--;
        }

        while (right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};
