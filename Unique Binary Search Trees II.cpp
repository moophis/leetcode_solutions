// http://oj.leetcode.com/problems/unique-binary-search-trees-ii/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Should really care about how function returns.
class Solution {
    vector<TreeNode*>* generate(int from, int to) {
        vector<TreeNode *>* ret = new vector<TreeNode *>();
        
        if (from < 1 || from > to) {
            ret->push_back(nullptr);
            return ret;
        }
        
        for (int i = from; i <= to; i++) {
            vector<TreeNode *>* rleft = generate(from, i - 1);
            vector<TreeNode *>* rright = generate(i + 1, to);
            
            for (int j = 0; j < rleft->size(); j++) {
                for (int k = 0; k < rright->size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = (*rleft)[j];
                    root->right = (*rright)[k];
                    
                    ret->push_back(root);
                }
            }
        }
        
        return ret;
    }
    
public:
    vector<TreeNode *> generateTrees(int n) {
        return *generate(1, n);
    }
};