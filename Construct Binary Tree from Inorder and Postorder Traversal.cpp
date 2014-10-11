/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
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
 // Without using additional data structures
class Solution {
    TreeNode *do_build(vector<int> &inorder, int in_start, int in_end, vector<int> &postorder, int po_start, int po_end) {
        if (in_end >= inorder.size() || po_end >= postorder.size() || in_start > in_end || po_start > po_end) {
            return nullptr; 
        }
        if (in_start == in_end && po_start == po_start) {
            return new TreeNode(inorder[in_start]);
        }
        
        int rootval = postorder[po_end];
        TreeNode *root = new TreeNode(rootval);
        
        // find root val in inorder vector
        int idx = -1;
        for (int i = in_start; i <= in_end; i++) {
            if (inorder[i] == rootval) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            // error case: bad inorder array
            return nullptr;
        }
        
        int leftsize = idx - in_start;
        root->left = do_build(inorder, in_start, idx - 1, postorder, po_start, po_start + leftsize - 1);
        root->right = do_build(inorder, idx + 1, in_end, postorder, po_start + leftsize, po_end - 1);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return do_build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

// Use a hashmap to buffer inorder index
class Solution {
    unordered_map<int, int> in_index; // <val, index>
    TreeNode *do_build(vector<int> &inorder, int root_val, int in_start, int in_end,
                       vector<int> &postorder, int po_start, int po_end) {
        TreeNode *root = new TreeNode(root_val);
        int in_root_index = in_index[root_val];
        
        // base case
        if (in_start > in_end || po_start > po_end) {
            return nullptr;
        }
        
        if (in_root_index > in_start) {
            int leftsize = in_root_index - in_start;
            root->left = do_build(inorder, postorder[po_start + leftsize - 1], 
                                  in_start, in_start + leftsize - 1, 
                                  postorder, po_start, po_start + leftsize - 1);
        }
        if (in_root_index < in_end) {
            int rightsize = in_end - in_root_index;
            root->right = do_build(inorder, postorder[po_end - 1], 
                                   in_root_index + 1, in_end, 
                                   postorder, po_end - rightsize, po_end - 1);
        }
        
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size()) {
            return nullptr;
        }
        if (inorder.size() == 0) {
            return nullptr;
        }
        
        for (int i = 0; i < inorder.size(); i++) {
            in_index[inorder[i]] = i;
        }
        
        return do_build(inorder, postorder[postorder.size()-1], 0, inorder.size() - 1,
                        postorder, 0, postorder.size() - 1);
    }
};