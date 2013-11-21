/*
 * Given a binary tree and a sum, find all root-to-leaf paths 
 * where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 *	return
 *	[
 *	   [5,4,11,2],
 *	   [5,8,4,5]
 *	]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        
        if (root == nullptr) {
            return ret;
        }
        
        do_pathsum(root, sum, ret);
        return ret;
    }
    
    void do_pathsum(TreeNode *root, const int sum, vector<vector<int> > &ret) {
        static int cur = 0;
        static vector<int> s;
    
        cur += root->val;    // update current sum
        s.push_back(root->val);
        
        if (root->left != nullptr)
            do_pathsum(root->left, sum, ret);
        if (root->right != nullptr)
            do_pathsum(root->right, sum, ret);
        if (root->left == nullptr && root->right == nullptr) { // base case
            if (sum == cur) {
                ret.push_back(s);
            }
        }
        
        s.pop_back();      // backtracking
        cur -= root->val;
    }
};