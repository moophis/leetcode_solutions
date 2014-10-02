// https://oj.leetcode.com/problems/recover-binary-search-tree/

// Better solution: keep track of two wrong nodes
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
    void do_recover(TreeNode *root, TreeNode* &first, TreeNode* &second, TreeNode* &last) {
        if (root == nullptr) { 
            return;
        }
        
        do_recover(root->left, first, second, last);
        
        if (first == nullptr && root->val < last->val) {
            first = last;  // be careful
        }
        if (first != nullptr && root->val < last->val) {
            second = root; // be careful
        }
        
        last = root;
        do_recover(root->right, first, second, last);
    }
    
public:
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *last = new TreeNode(INT_MIN);
        
        do_recover(root, first, second, last);
        swap(first->val, second->val);
    }
};

// O(n) spaces
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