// https://oj.leetcode.com/problems/symmetric-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        
        vector<TreeNode *> v1 = {root->left, root->right}, v2;
        vector<TreeNode *> &cur_level = v1, &next_level = v2;

        // start from the second level
        while (!cur_level.empty()) {
            int size = cur_level.size();
            if (size % 2) {
                return false;
            }
            
            // validate current level
            for (int s = 0, e = size - 1; s < e; s++, e--) {
                if ((cur_level[s] != nullptr) ^ (cur_level[e] != nullptr)) {
                    return false;
                }
                if (cur_level[s] != nullptr && cur_level[e] != nullptr) {
                    if (cur_level[s]->val != cur_level[e]->val) {
                        return false;
                    } 
                }
            }
            
            // assemble next level
            for (int i = 0; i < size; i++) {
                if (cur_level[i] != nullptr) {
                    next_level.push_back(cur_level[i]->left);
                    next_level.push_back(cur_level[i]->right);
                }
            }
            
            cur_level.clear();
            swap(cur_level, next_level);
        }
        
        return true;
    }
};

// recursive
class Solution {
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if ((left != nullptr) ^ (right != nullptr)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        
        return compare(left->right, right->left) && compare(left->left, right->right);
    }
    
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return compare(root->left, root->right);
    }
};