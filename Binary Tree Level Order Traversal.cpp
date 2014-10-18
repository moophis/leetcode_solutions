/**
 * Given a binary tree, return the level order traversal 
 * of its nodes' values. (ie, from left to right, level by level).
 *
 *  For example:
 *  Given binary tree {3,9,20,#,#,15,7},
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 *  return its level order traversal as:
 *  [
 *    [3],
 *    [9,20],
 *    [15,7]
 *  ]
 */
 
// dfs
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
    void dfs(TreeNode *root, vector<vector<int> > &ret, int level) {
        if (root == nullptr) {
            return;
        }
        if (level >= ret.size()) {
            ret.push_back({root->val});
        } else {
            ret[level].push_back(root->val);
        }
        dfs(root->left, ret, level + 1);
        dfs(root->right, ret, level + 1);
    }
    
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        dfs(root, ret, 0);
        
        return ret;
    }
};

// bfs
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (root == nullptr) {
            return ret;
        }
        
        queue<TreeNode *> q1, q2;
        queue<TreeNode *> &cur_q = q1, &next_q = q2;
        vector<int> line;
        
        cur_q.push(root);
        while (!cur_q.empty()) {
            TreeNode *node = cur_q.front();
            cur_q.pop();
            line.push_back(node->val);
            
            if (node->left != nullptr) {
                next_q.push(node->left);
            }
            if (node->right != nullptr) {
                next_q.push(node->right);
            }
            
            if (cur_q.empty()) {
                ret.push_back(line);
                line.clear();
                swap(cur_q, next_q);
            }
        }
        
        return ret;
    }
};