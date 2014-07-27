// https://oj.leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void reverse(ListNode* &begin, ListNode* cur, ListNode* &end) {
        if (cur == nullptr || begin->next == nullptr) {
            return;
        }
        if (cur == end) {
            begin->next->next = end->next;
            begin->next = end;
            return;
        }
        
        ListNode *old_next = cur->next;
        reverse(begin, cur->next, end);
        if (cur != begin) {
            old_next->next = cur;
        }
    }
    
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur_head = dummy, *cur_end = cur_head;
        
        while (cur_head != nullptr) {
            cur_end = cur_head;
            for (int i = 0; i < k; i++) {
                cur_end = cur_end->next;
                if (cur_end == nullptr) {
                    break;
                }
            }
            if (cur_end == nullptr) {
                return dummy->next;
            }
            
            reverse(cur_head, cur_head, cur_end);
            
            for (int i = 0; i < k; i++) {
                cur_head = cur_head->next;
                if (cur_head == nullptr) {
                    break;
                }
            }    
        }
        
        return dummy->next;
    }
};