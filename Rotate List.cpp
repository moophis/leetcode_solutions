// https://oj.leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || k <= 0) {
            return head;
        }
        
        int size = 1;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            size++;
            cur = cur->next;
        }
              
        ListNode *tail = head;
        k = k % size;
        for (int i = 0; i < size - k - 1; i++) {
            tail = tail->next;
        }
        cur->next = head;
        head = tail->next;
        tail->next = nullptr;
        
        return head; 
    }
};