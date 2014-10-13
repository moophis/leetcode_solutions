// https://oj.leetcode.com/problems/reverse-linked-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// One pass, cleaner code
class Solution {
    void reverse(ListNode *dummy, ListNode* &end, ListNode *head, int cur_cnt, const int n) {
        if (head == nullptr) {
            return;
        }
        if (cur_cnt == n) {
            end = head->next;
            dummy->next = head;
            return;
        }
        
        ListNode *t = head->next;
        reverse(dummy, end, head->next, cur_cnt + 1, n);
        t->next = head;
    }
    
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        if (m <= 0 || n < m) {
            return nullptr;
        }
        
        ListNode dummy(INT_MIN);
        dummy.next = head;
        int cnt = 0;
        ListNode *cur = &dummy;
        while (cur != nullptr && cnt < m - 1) {
            cur = cur->next;
            cnt++;
        }
        if (cur == nullptr) {
            return nullptr;  // error: m is too large
        }
        
        ListNode *t = cur->next;
        ListNode *end = nullptr;
        reverse(cur, end, t, m, n);
        t->next = end;
        
        return dummy.next;
    }
};

class Solution {
    ListNode *__reverse(ListNode* current, ListNode* &begin, ListNode* &end,
                        int cur_index, const int FROM, const int TO) {
        if (current == nullptr) {
            return nullptr;
        }                  
        if (cur_index == TO) {
            begin->next = current;
            end = current->next;
            return current;
        }  
        
        ListNode *node = __reverse(current->next, begin, end, cur_index+1, FROM, TO);
        if (node == nullptr) {
            return nullptr;
        }
        node->next = current;
        
        return current;
    }

    ListNode *reverse(ListNode* current, ListNode* &begin, ListNode* &end,
                        const int FROM, const int TO) {
        if (current == nullptr) {
            return nullptr;
        }
        
        int cur_index = 0;
        while (cur_index < FROM - 1) {
            cur_index++;
            if (current == nullptr) {
                return nullptr;
            }
            current = current->next;
        }                    
        
        begin = current;
        return __reverse(current->next, begin, end, cur_index+1, FROM, TO); 
    } 
    
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        if (m <= 0 || n < m) {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *begin = nullptr, *end = nullptr;
        ListNode *ret = reverse(dummy, begin, end, m, n);
        if (ret != nullptr && begin != nullptr) {
            ret->next = end;
        } else {
            return nullptr;
        }
        
        return dummy->next;
    }
};