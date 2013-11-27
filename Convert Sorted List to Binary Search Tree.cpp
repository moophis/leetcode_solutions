/**
 * Given a singly linked list where elements are sorted 
 * in ascending order, convert it to a height balanced BST.
 */

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
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == nullptr) {
            return nullptr;
        }
        
        return do_sl2b(head, nullptr);
    }
    
    TreeNode *do_sl2b(ListNode *head, ListNode *tail) {
        ListNode *slow, *fast;
        
        slow = fast = head;
        
        if (slow == tail) {  // base case
            return nullptr;
        }
        if (slow->next == nullptr) {  // base case
            return new struct TreeNode(slow->val);
        }
        
        while (fast != tail && fast->next != tail) {  // find middle point
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *ret = new struct TreeNode(slow->val);
        ret->left = do_sl2b(head, slow);
        ret->right = do_sl2b(slow->next, tail);
        return ret;
    }
};