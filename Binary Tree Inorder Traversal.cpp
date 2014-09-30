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
    void recursive(vector<int> &result, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        recursive(result, root->left);
        result.push_back(root->val);
        recursive(result, root->right);
    }
        
    void iterative_not_optimal(vector<int> &result, TreeNode *root) {
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
    
    void iterative(vector<int> &result, TreeNode *root) {
        if (root == nullptr) return;
    
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (!stk.empty() || cur) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                cur = stk.top();
                stk.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    
    // Non-stack, non-recursion solution
    // Temporarily change the right child of each leaf to the next node to
    // be visited and change it back later on.
    void iterative_morris_traversal(vector<int> &res, TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->left != nullptr) {
                TreeNode *next = cur->left;
                while (next->right != nullptr && next->right != cur) {
                    next = next->right;
                }
                if (next->right == nullptr) {
                    next->right = cur;
                    cur = cur->left;
                } else {
                    next->right = nullptr;
                    res.push_back(cur->val); // internal tree node
                    cur = cur->right;
                }
            } else {  // leaf
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        // recursive(ret, root);
        // iterative(ret, root);
        iterative_morris_traversal(ret, root);
        
        return ret;
    }
};