// https://oj.leetcode.com/problems/recover-binary-search-tree/

// O(n) spaces
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
    void inorder(TreeNode *root, vector<TreeNode*> &list, vector<int> &vals) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, list, vals);
    }
public:
    void recoverTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        vector<TreeNode*> list;
        vector<int> vals;
        
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++) {
            list[i]->val = vals[i];
        }
    }
};