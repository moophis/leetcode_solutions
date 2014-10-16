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
    TreeNode *convert(vector<int> &num, int start, int end) {
        if (start > end) {
            return nullptr;
        }    
        
        int mid = start + (end - start) / 2;
        TreeNode *cur = new TreeNode(num[mid]);
        cur->left = convert(num, start, mid - 1);
        cur->right = convert(num, mid + 1, end);
        
        return cur;
    }
    
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert(num, 0, num.size() - 1);
    }
};