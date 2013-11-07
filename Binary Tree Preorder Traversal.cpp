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
    void do_traverse(vector<int> &record, TreeNode *root) {
        if (root == nullptr)
            return;
        record.push_back(root->val);   
        do_traverse(record, root->left);
        do_traverse(record, root->right); 
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> result ;
        
        do_traverse(result, root);
        return result;
    }
};

// Non-recursive by using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<TreeNode *> stk;
        vector<int> record;
        TreeNode *cur;
        stk.push_back(root);

        
        while (!stk.empty()) {
            cur = stk.back();
            stk.pop_back();
            
            if (cur == nullptr)
                continue;
                
            record.push_back(cur->val);
            stk.push_back(cur->right);
            stk.push_back(cur->left);
        }
        
        return record;
    }
};
