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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode *> p_queue, q_queue;
        
        if (p != nullptr)
            p_queue.push(p);
        if (q != nullptr)
            q_queue.push(q);
  
        while (!p_queue.empty() && !q_queue.empty()) { 
            p = p_queue.front(); 
            q = q_queue.front(); 
            p_queue.pop();
            q_queue.pop();
            if (p == nullptr && q == nullptr)
                continue;
            if (p == nullptr || q == nullptr)
                return false;
            if (p->val != q->val)
                return false;
           
            p_queue.push(p->left);
            p_queue.push(p->right);            
            q_queue.push(q->left);
            q_queue.push(q->right);
        }
        
        return p_queue.size() == q_queue.size();
    }
};