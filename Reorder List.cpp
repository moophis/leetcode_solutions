// http://oj.leetcode.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // iterative: first split list into half, reverse the second one, and then merge those two
    void reorder_iterative(ListNode *head, ListNode *append) {
        if (append->next == nullptr || append == head) {
            return;
        }
        ListNode dummy(INT_MIN);
        dummy.next = append->next;
        append->next = nullptr;
        
        // reverse the second half list
        ListNode *pre = nullptr;
        ListNode *cur = dummy.next;
        ListNode *next;
        ListNode *newhead;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            if (next == nullptr) {
                newhead = cur;
            } else {
                pre = cur;
            }
            cur = next;
        }
        dummy.next = newhead;
    
        // interleave two lists
        cur = head;
        while (cur != nullptr && dummy.next != nullptr) {
            ListNode *t = cur->next;
            ListNode *p = dummy.next;
            cur->next = dummy.next;
            dummy.next = p->next;
            p->next = t;
            cur = t;
        }
    }
    
    // recursive
    void reorder(ListNode* &current, ListNode* append) {
        if (append->next == nullptr || append->next == current) {
            return;
        }
        
        reorder(current, append->next);
        
        ListNode *moved = append->next;
        append->next = moved->next;
        moved->next = current->next;
        current->next = moved;
        current = moved->next;
    }
    
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
            }
        }
        
        // reorder_iterative(head, slow);
        reorder_iterative(head, slow);
    }
};