/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    unordered_map<int, int> in_index; // <val, index>
    TreeNode *do_build(vector<int> &inorder, int root_val, int in_start, int in_end,
                       vector<int> &preorder, int pr_start, int pr_end) {
        TreeNode *root = new TreeNode(root_val);
        int in_root_index = in_index[root_val];
        
        // base case
        if (in_start > in_end || pr_start > pr_end) {
            return nullptr;
        }                
        
        if (in_root_index > in_start) {
            int leftsize = in_root_index - in_start;
            root->left = do_build(inorder, preorder[pr_start + 1],
                                  in_start, in_root_index - 1,
                                  preorder, pr_start + 1, pr_start + leftsize);
        }
        if (in_root_index < in_end) {
            int rightsize = in_end - in_root_index;
            root->right = do_build(inorder, preorder[pr_end - rightsize + 1],
                                  in_root_index + 1, in_end,
                                  preorder, pr_end - rightsize + 1, pr_end);
        }    
        
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() != preorder.size()) {
            return nullptr;
        }
        if (inorder.size() == 0) {
            return nullptr;
        }
        
        for (int i = 0; i < inorder.size(); i++) {
            in_index[inorder[i]] = i;
        }
        
        return do_build(inorder, preorder[0], 0, inorder.size() - 1,
                        preorder, 0, preorder.size() - 1);
    }
};