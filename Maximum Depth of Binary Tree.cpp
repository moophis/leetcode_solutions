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
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int leftcnt, rightcnt, maxd;
        // base case
        if (root == nullptr) {
            return 0;
        } 
        
        leftcnt = maxDepth(root->left);
        rightcnt = maxDepth(root->right);
        maxd = leftcnt >= rightcnt ? leftcnt : rightcnt;
        
        return ++maxd;
    }
};