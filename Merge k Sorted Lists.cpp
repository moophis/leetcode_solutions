// http://oj.leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Use min-heap, time: O(nlogk)
struct ListNodeComparision {
    bool operator() (ListNode* &lhs, ListNode* &rhs) {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int lists_size = lists.size();
        if (lists_size == 0) {
            return nullptr;
        }
        if (lists_size == 1) {
            return lists[0];
        }
        
        priority_queue<ListNode *, vector<ListNode *>, ListNodeComparision> node_pool;  // min-heap
        
        // first push the first element from all lists into the heap
        for (int i = 0; i < lists_size; i++) {
            if (lists[i] != nullptr) {
                node_pool.push(lists[i]);
            }
        }
        
        // then always extract the node with min value
        ListNode dummy(INT_MIN);
        ListNode *pre = &dummy;
        while (!node_pool.empty()) {
            ListNode *cur = node_pool.top();
            node_pool.pop();
            pre->next = cur;
            pre = pre->next;
            if (cur->next != nullptr) {
                node_pool.push(cur->next);
            }
        } 
        
        return dummy.next;
    }
};

// Naive implementation
class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode *head1 = new ListNode(INT_MIN);
        ListNode *head2 = new ListNode(INT_MIN);
        head1->next = l1;
        head2->next = l2;
        
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        
        while (p1->next != nullptr && p2->next != nullptr) {
            if (p1->next->val > p2->next->val) {
                ListNode *t = p2->next;
                p2->next = t->next;
                t->next = p1->next;
                p1->next = t;
            }
            p1 = p1->next;
        }
        if (p1->next == nullptr) {
            p1->next = p2->next;
        }
        
        return head1->next;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *ret = nullptr;
        
        if (lists.size() == 0) {
            return ret;
        }
        if (lists.size() == 1) {
            return lists.back();
        }
        
        for (int i = 0; i < lists.size(); i++) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        
        return ret;
    }
};