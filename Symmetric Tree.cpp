/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive way
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == nullptr)
            return true;
        
        return compare(root->left, root->right);
    }
    
    bool compare(TreeNode *l, TreeNode *r) {
        bool valcomp = false;
        
        if ((l == nullptr && r != nullptr)
             || (l != nullptr && r == nullptr)) {
            return false;     
        } else if (l == nullptr && r == nullptr) {
            return true;
        } else {
            valcomp = (l->val == r->val);
            return valcomp && compare(l->left, r->right)
                           && compare(l->right, r->left);
        }
    }
};

// Iterative way
// refer to http://fisherlei.blogspot.com/2013/01/leetcode-symmetric-tree.html
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeNode *cur;
        vector<TreeNode *> pre_level, cur_level;
        
        if (root == nullptr)
            return true;
        
        pre_level.push_back(root);
        while (pre_level.size() > 0) {
            while (pre_level.size() > 0) {
                cur = pre_level.back();
                pre_level.pop_back();
                if (cur == nullptr)
                    continue;
                cur_level.push_back(cur->left);
                cur_level.push_back(cur->right);
            }
            
            int begin = 0, end = static_cast<int>(cur_level.size()) - 1;
            if ((end + 1) % 2) {
                return false;
            }
            while (begin < end) {
                int lval = cur_level[begin] ? cur_level[begin]->val : -1;
                int rval = cur_level[end] ? cur_level[end]->val : -1;
                if (lval != rval) {
                    return false;
                }
                begin++;
                end--;
            }
            pre_level.clear();
            pre_level.insert(pre_level.begin(), cur_level.begin(), cur_level.end());
            cur_level.clear();
        }
        
        return true;
    }
};