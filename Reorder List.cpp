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
    void do_reorder(ListNode *&current, ListNode *appended) {
        if (appended == nullptr || appended->next == nullptr
                                || appended == current) {
            return;
        }
        
        do_reorder(current, appended->next);
        
        ListNode *moved = appended->next;
        appended->next = moved->next; // nullptr
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
        
        do_reorder(head, slow);
    }
};