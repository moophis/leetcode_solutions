// https://oj.leetcode.com/problems/binary-tree-inorder-traversal/

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
    // recursive solution is pretty trivial
    void recursive(vector<int> &result, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        recursive(result, root->left);
        result.push_back(root->val);
        recursive(result, root->right);
    }

    // iterative solution
    void iterative(vector<int> &result, TreeNode *root) {
        vector<TreeNode *> stk;
        unordered_set<TreeNode *> visited;
        
        if (root == nullptr) {
            return;
        }
        stk.push_back(root);
        visited.emplace(root);
        while (!stk.empty()) {
            TreeNode *cur = stk.back();
            while (cur->left != nullptr && visited.count(cur->left) == 0) {
                stk.push_back(cur->left);
                visited.emplace(cur->left);
                cur = cur->left;
            }
            result.push_back(cur->val);
            stk.pop_back();
            if (cur->right != nullptr) {
                stk.push_back(cur->right);
                visited.count(cur->right);
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        // recursive(ret, root);
        iterative(ret, root);
        
        return ret;
    }
};