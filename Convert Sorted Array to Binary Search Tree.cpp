// http://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    // [low, hi]
    void convert(vector<int> &num, int low, int hi, TreeNode* &root) {
        if (low < 0 || hi >= num.size() || low > hi) 
            return; 
        
        int mid = low + (hi - low) / 2;
        
        if (root == nullptr) {
            root = new TreeNode(num[mid]);
        } else {
            root->val = num[mid];
        }
        
        convert(num, low, mid - 1, root->left);
        convert(num, mid + 1, hi, root->right);
    }
    
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return nullptr;
        }
        
        TreeNode *root = nullptr;
        
        convert(num, 0, num.size() - 1, root);
        return root;
    }
};