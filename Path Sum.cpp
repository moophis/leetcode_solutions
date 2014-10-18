/**
 * Given a binary tree and a sum, determine if the tree has a 
 * root-to-leaf path such that adding up all the values along 
 * the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \      \
 *       7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool find_sum(TreeNode *root, const int sum, int cur) {
        if (root == nullptr) {
            return false;
        }
        
        cur += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return (sum == cur);
        }
        return find_sum(root->left, sum, cur) || find_sum(root->right, sum, cur);
    }
    
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return find_sum(root, sum, 0);
    }
};