/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        int num_at_this_level, num_at_next_level = 0;
        
        if (root == nullptr)
            return;
        num_at_this_level = 1;
        q.push(root);
        
        while (!q.empty()) {
            TreeLinkNode *cur = q.front();
            q.pop();
            
            if (cur->left != nullptr) {
                q.push(cur->left);
                num_at_next_level++;
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
                num_at_next_level++;
            }
            
            if (--num_at_this_level > 0) {
                cur->next = q.front();
            } else {
                cur->next = nullptr;
                num_at_this_level = num_at_next_level;
                num_at_next_level = 0;
            }
        }
    }

};