/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

// Use in-place merge sort
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void mergesort(ListNode *head, ListNode *tail) {
        if (head == nullptr || head == tail || head->next == tail) {
            return;
        }
        if (head->next->next == tail) {
            return;  // only contains one element
        }
        
        ListNode *slow = head, *fast = head;
        // find middle node (slow)
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // divide
        mergesort(head, slow->next);
        mergesort(slow, tail);
        
        // merge
        ListNode bound(INT_MAX);
        bound.next = slow->next;
        slow->next = &bound;
        ListNode *p1 = head;
        ListNode *p2 = &bound;
        while (p1->next != &bound && p2->next != tail) {
            if (p1->next->val > p2->next->val) {
                ListNode *t = p2->next;
                p2->next = t->next;
                t->next = p1->next;
                p1->next = t;
            }
            p1 = p1->next;
        }
        while (p1->next != &bound) {
            p1 = p1->next;
        }
        p1->next = bound.next;
    }
    
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        
        mergesort(&dummy, nullptr);
        
        return dummy.next;
    }
};