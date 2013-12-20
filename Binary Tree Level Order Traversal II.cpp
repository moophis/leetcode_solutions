/**
 * Given a binary tree, return the bottom-up level order traversal of 
 * its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * return its bottom-up level order traversal as:
 * [
 *  [15,7]
 *  [9,20],
 *  [3],
 * ]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > levels;
        deque<TreeNode *> q_cur, q_next;
        vector<int> t;
        
        if (root == nullptr) {
            return levels;
        }
        
        q_cur.push_back(root);
        while (!q_cur.empty()) {
            TreeNode *current = q_cur.front();
            q_cur.pop_front();
            
            t.push_back(current->val);
            
            if (current->left != nullptr) {
                q_next.push_back(current->left);
            }
            if (current->right != nullptr) {
                q_next.push_back(current->right);
            }            
            
            if (q_cur.empty()) {
                q_cur = q_next;
                q_next.clear();
                levels.push_back(t);
                t.clear();
            }
        }
        
        vector<vector<int> > ret;
        for (auto rit = levels.rbegin(); rit != levels.rend(); ++rit) {
            ret.push_back(*rit);
        }
        
        return ret;
    }
};
