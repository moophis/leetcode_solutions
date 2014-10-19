/**
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example,
 * Given
 *
 *       1
 *      / \
 *     2   5
 *    / \   \
 *   3   4   6
 * The flattened tree should look like:
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
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

// O(n): cache the last node of each sub-list
class Solution {
    TreeNode *do_flatten(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        TreeNode *left_end = do_flatten(root->left);
        TreeNode *right_end = do_flatten(root->right);
        if (left_end != nullptr) {
            TreeNode *t = root->right;
            root->right = root->left;
            root->left = nullptr;
            left_end->right = t;
        }
        if (right_end != nullptr) {
            return right_end;
        } else if (left_end != nullptr) {
            return left_end;
        } else {
            return root;
        }
    }
    
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        do_flatten(root);
    }
};

// O(nlogn): cleaner recursive solution
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }       
        
        flatten(root->left);
        flatten(root->right);
        TreeNode *right = root->right; 
        if (root->left != nullptr) {
            root->right = root->left;
            root->left = nullptr;
            TreeNode *cur = root->right;
            while (cur->right != nullptr) {
                cur = cur->right;
            }
            cur->right = right;
        } 
    }
};

/*
 * Recursively swap the left child and right child until reach 
 * the right bottom. Then go back while finding any left children, 
 * concatenate them to the right bottom, recursively flatten
 * them until no left child.
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (root == nullptr) 
            return;
        TreeNode *last = do_flatten(root);
    }
    
    TreeNode *do_flatten(TreeNode *root) {
        if (root->left != nullptr) {
            swap(root->left, root->right);
        } 
        if (root->right == nullptr) { // base case: buttom of right child
            return root;
        }
        
        TreeNode *cont = do_flatten(root->right);
        if (root->left == nullptr) {
            return cont;
        }
        swap(cont->right, root->left);
        
        return do_flatten(cont->right);
    }
};