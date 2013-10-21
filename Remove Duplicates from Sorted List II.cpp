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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *first, *second;
        ListNode *begin;
        
        if (head == nullptr)
            return nullptr;
        
        begin = new ListNode(head->val - 1);
        begin->next = head;
        first = begin;
        second = head->next;
        
        while (second != nullptr) {
            if (first->next == second) {
                // Maintain the relative location where *first* is in
                // the two hops left of *second*
                second = second->next;
            } else if (first->next->val != second->val) {
                first = first->next;
                second = second->next;
            } else {
                while (second != nullptr &&
                       second->val == first->next->val) {
                    second = second->next;        
                }
                first->next = second;
            }
        }
        
        return begin->next;
    }
};