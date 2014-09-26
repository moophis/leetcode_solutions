// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = dummy;
        while (n > 0 && fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            n--;
        }
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};