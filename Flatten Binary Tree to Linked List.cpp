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

/*
 * Recursively swap the left child and right child until reach 
 * the right bottom. Then go back while finding any left children, 
 * concatenate them to the right bottom, recursively flatten
 * them until no left child.
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