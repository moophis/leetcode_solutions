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
        list<TreeNode *> cur, next;
        vector<vector<int> > ret;
        vector<int> vec;
        
        if (root == nullptr) {
            return ret;
        }
        
        cur.push_back(root);
        while (!cur.empty()) {
            TreeNode *t = cur.front();
            cur.pop_front();
            vec.push_back(t->val);
            
            if (t->left != nullptr) {
                next.push_back(t->left);
            }
            if (t->right != nullptr) {
                next.push_back(t->right);
            }
            
            if (cur.empty()) {
                cur = next;
                next.clear();
                ret.push_back(vec);
                vec.clear();
            }
        }
        
        return ret;
    }
};