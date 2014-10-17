// http://oj.leetcode.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Do not need to swap nodes in place. Use two lists instead.
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(INT_MIN);
        ListNode smaller(INT_MIN);
        dummy.next = head;
        ListNode *cur = &dummy;
        ListNode *scur = &smaller;
        while (cur->next != nullptr) {
            if (cur->next->val < x) {
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = scur->next;
                scur->next = t;
                scur = scur->next;
            } else {
                cur = cur->next;
            }
        }
        scur->next = dummy.next;
        
        return smaller.next;
    }
};

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