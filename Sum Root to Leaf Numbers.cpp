// http://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void iterate_num(TreeNode *root, vector<int> &numbers, int current) {
        int new_current = current * 10 + root->val;
        
        if (root->left == nullptr && root->right == nullptr) {
            numbers.push_back(new_current);
            return;
        }    
        
        if (root->left != nullptr) {
            iterate_num(root->left, numbers, new_current);
        }
        if (root->right != nullptr) {
            iterate_num(root->right, numbers, new_current);
        }
    }
    
public:
    int sumNumbers(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        vector<int> numbers;
        int sum = 0;
        iterate_num(root, numbers, 0);
        
        for (int i = 0; i < numbers.size(); i++) {
            sum += numbers[i];
        }
        
        return sum;
    }
};