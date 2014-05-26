/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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