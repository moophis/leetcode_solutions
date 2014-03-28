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
public:
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        
        mergesort(dummy, nullptr);
        
        return dummy->next;
    }
    
    void mergesort(ListNode *vhead, ListNode *vtail) {
        if (vhead == nullptr || vhead == vtail || vhead->next == nullptr ||
            vhead->next->next == nullptr || vhead->next->next == vtail) {
            return;  // base case & error    
        }
        
        ListNode *slow = vhead;
        ListNode *fast = vhead;
        
        while (fast != vtail && fast->next != vtail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        mergesort(vhead, slow->next);
        mergesort(slow, vtail);
        
        ListNode *p1, *p2, *cur;
        ListNode *overhead = new ListNode(0);
        overhead->next = slow->next;
        slow->next = overhead;
        
        // merge
        p1 = vhead;
        p2 = overhead;
        while (p1->next != overhead || p2->next != vtail) {
            if (p1->next != overhead && p2->next != vtail) {
                if (p1->next->val > p2->next->val) {
                    ListNode *t = p2->next;
                    p2->next = p2->next->next;
                    t->next = p1->next;
                    p1->next = t;
                } 
                p1 = p1->next;
            } else if (p1->next != overhead) {
                while (p1->next != overhead) {
                    p1 = p1->next;
                }
                p1->next = vtail;
                break;
            } else {
                p1->next = p2->next;
                break;
            }
        }
    }
};