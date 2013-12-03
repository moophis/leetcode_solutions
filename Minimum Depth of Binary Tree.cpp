/**
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest 
 * path from the root node down to the nearest leaf node.
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
    int min_helper(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        int min_left = INT_MAX;
        int min_right = INT_MAX;
        
        if (root->left != nullptr) {
            min_left = min_helper(root->left);
        }
        if (root->right != nullptr) {
            min_right = min_helper(root->right);
        }
        
        return 1 + min(min_left, min_right);
    }
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        return min_helper(root);
    }
};