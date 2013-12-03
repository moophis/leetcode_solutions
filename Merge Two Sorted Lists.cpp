/**
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes 
 * of the first two lists.
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode *head1 = new ListNode(0);
        ListNode *head2 = new ListNode(1);
        head1->next = l1;
        head2->next = l2;
        ListNode *cur = head1;
        
        while (cur->next != nullptr && head2->next != nullptr) {
            if (cur->next->val < head2->next->val) {
                cur = cur->next;       
            } else {
                ListNode *t = head2->next;
                head2->next = t->next;
                t->next = cur->next;
                cur->next = t;
                cur = cur->next;
            }
        }
        if (cur->next == nullptr) {
            cur->next = head2->next;
        }
        
        return head1->next;
    }
};