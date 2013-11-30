/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined
 * as a binary tree in which the depth of the two subtrees of 
 * every node never differ by more than 1.
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
    int max_depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        return 1 + max(max_depth(root->left), max_depth(root->right));
    }
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        
        return abs(max_depth(root->left) - max_depth(root->right)) < 2
              && isBalanced(root->left) && isBalanced(root->right);
    }
};