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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        
        ListNode *sorted = dummy;
        bool swapped = false;
        while (sorted->next != nullptr) {
            ListNode *s = sorted->next;
                
            for (ListNode *cur = dummy; cur != sorted; cur = cur->next) {
                if (s->val <= cur->next->val) {
                    ListNode *t = cur->next;
                    sorted->next = s->next;
                    s->next = t;
                    cur->next = s;
                    swapped = true;
                    break;
                }
            }
            
            if (!swapped) {
                sorted = sorted->next;
            } else {
                swapped = false;
            }
        }
        
        return dummy->next;
    }
};