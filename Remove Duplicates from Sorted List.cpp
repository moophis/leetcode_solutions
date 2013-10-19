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
        ListNode *cur = head;
        int recent;
        
        if (head != nullptr) {
            recent = head->val;
        } else {
            return nullptr;
        }
        
        while (cur != nullptr) {
            if (cur->next != nullptr) {
                while (cur->next != nullptr && cur->next->val == recent) {
                    ListNode *t = cur->next;
                    cur->next = cur->next->next;
                    delete t;
                } 
                if (cur->next != nullptr)
                    recent = cur->next->val;
            }
            cur = cur->next;
        }
        
        return head;
    }
};