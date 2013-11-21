/* 
 * Given a binary tree, return the zigzag level order traversal of 
 * its nodes' values. (ie, from left to right, then right to left 
 * for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *  return its zigzag level order traversal as:
 *  [
 *    [3],
 *    [20,9],
 *    [15,7]
 *  ]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<TreeNode *> buf_l, buf_r;
        vector<vector<int> > result;
        bool l2r = true;    // node rendering direction (true: left to right)
        
        if (root == nullptr) {
            return result;
        }
        
        buf_l.push_back(root);
        while (!buf_l.empty() || !buf_r.empty()) {
            vector<int> v;
            if (l2r) {
                // iterate from left to right
                while (!buf_l.empty()) {
                    TreeNode *cur = buf_l.back();
                    buf_l.pop_back();
                    v.push_back(cur->val);
                    if (cur->left != nullptr) {
                        buf_r.push_back(cur->left);
                    }
                    if (cur->right != nullptr) {
                        buf_r.push_back(cur->right);
                    }
                }
                l2r = false;
            } else {
                // iterate from right to left
                while (!buf_r.empty()) {
                    TreeNode *cur = buf_r.back();
                    buf_r.pop_back();
                    v.push_back(cur->val);
                    if (cur->right != nullptr) {
                        buf_l.push_back(cur->right);
                    }
                    if (cur->left != nullptr) {
                        buf_l.push_back(cur->left);
                    }
                }
                l2r = true;
            }
            result.push_back(v);
        }
        
        return result;
    }
};