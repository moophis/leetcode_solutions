// https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *do_convert(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return nullptr;
        }
        
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *tn = new TreeNode(slow->val);
        tn->left = do_convert(head, slow);
        tn->right = do_convert(slow->next, tail);
        
        return tn;
    }

public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        return do_convert(head, nullptr);    
    }
};