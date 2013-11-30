/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 *  For example:
 *  Given binary tree {1,#,2,3},
 *     1
 *      \
 *       2
 *      /
 *     3
 *  return [3,2,1].
 *
 *  Note: Recursive solution is trivial, could you do it iteratively?
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
 
// recursive solution
class Solution {
    void do_postorder(TreeNode *root, vector<int> &ret) {
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(root->val);
            return;
        }
        
        if (root->left != nullptr) {
            do_postorder(root->left, ret);
        } 
        if (root->right != nullptr) {
            do_postorder(root->right, ret);
        }
        ret.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == nullptr) {
            return ret;
        }
        
        do_postorder(root, ret);
        return ret;
    }
};

// iterative solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<TreeNode *> stk;
        vector<int> ret;
        
        if (root == nullptr) {
            return ret;
        }
        
        stk.push_back(root);
        while (!stk.empty()) {
            TreeNode cur(stk.back()->val);
            cur.left = stk.back()->left;
            cur.right = stk.back()->right;
            
            // break the pointers to it children to meet the next predicate
            stk.back()->left = stk.back()->right = nullptr;  
            
            if (cur.left == nullptr && cur.right == nullptr) {
                ret.push_back(cur.val);
                stk.pop_back();
            }

            if (cur.right != nullptr) {
                stk.push_back(cur.right);
            }
            if (cur.left != nullptr) {
                stk.push_back(cur.left);
            }
        }
        
        return ret;
    }
};