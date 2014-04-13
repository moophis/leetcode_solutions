// http://oj.leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last = dummy;
                
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            
            slow->next = fast->next;
            fast->next = slow;
            last->next = fast;
            last = slow;
            fast = slow->next;
            slow = slow->next;
        }
        
        return dummy->next;
    }
};