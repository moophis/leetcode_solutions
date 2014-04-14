// http://oj.leetcode.com/problems/partition-list/

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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr)
            return nullptr;
            
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *pivot = dummy;
        ListNode *cur = dummy;
        
        while (cur->next != nullptr) {
            if (cur->next->val < x) {
                ListNode *t = cur->next;
                
                if (pivot->next == t) {
                    pivot = t;
                    cur = t;
                } else {
                    cur->next = t->next;
                    t->next = pivot->next;
                    pivot->next = t;
                    pivot = t;
                }           
            } else {
                cur = cur->next;  
            }
        }
        
        return dummy->next;
    }
};