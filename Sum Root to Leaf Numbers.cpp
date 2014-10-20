// http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void do_sum(TreeNode *root, int cur, int &sum) {
        if (root == nullptr) {
            return;
        }
        
        cur = cur * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += cur;
            return;
        }
        if (root->left != nullptr) {
            do_sum(root->left, cur, sum);
        }
        if (root->right != nullptr) {
            do_sum(root->right, cur, sum);
        }
    }
    
public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = 0;
        do_sum(root, 0, sum);
        return sum;
    }
};