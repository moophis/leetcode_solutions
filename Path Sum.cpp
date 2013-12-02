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
    bool find_path(TreeNode *root, int sum, int cur) {
        if (root->left == nullptr && root->right == nullptr) {
            return sum == cur + root->val;
        }
        
        bool left_match = false;
        bool right_match = false;
        
        if (root->left != nullptr) {
            left_match = find_path(root->left, sum, cur + root->val);
            if (left_match) {
                return true;
            }
        }
        if (root->right != nullptr) {
            right_match = find_path(root->right, sum, cur + root->val);
            if (right_match) {
                return true;
            }
        }  
        
        return false;
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root == nullptr) {
            return false;
        }
        
        int cur = 0;
        return find_path(root, sum, cur);
    }
};