// https://oj.leetcode.com/problems/validate-binary-search-tree/

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
    bool check_bound(TreeNode *root, int lower, int upper) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= lower || root->val >= upper) {
            return false;
        } 
        
        return check_bound(root->left, lower, root->val)
            && check_bound(root->right, root->val, upper);
    }
    
public:
    bool isValidBST(TreeNode *root) {
        return check_bound(root, INT_MIN, INT_MAX);
    }
};