
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// Optimal solution: iterative with constant space complexity.
// Use two pointers to traverse and connect node level by level.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        
        TreeLinkNode *high = root;
        TreeLinkNode *low = root->left;
        while (low != nullptr) {
            TreeLinkNode *cur = low;
            while (high != nullptr) {
                if (cur != high->left) {
                    cur->next = high->left;
                    cur = cur->next;
                }
                cur->next = high->right;
                cur = cur->next;
                high = high->next;
            }
            
            high = low;
            low = high->left;
        }
    }
};

// Recursion: no explicit additional space.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left != nullptr) {
            root->left->next = root->right;
        }
        if (root->right != nullptr && root->next != nullptr) {
            root->right->next = root->next->left;
        }
        
        connect(root->right);
        connect(root->left);
    }
};

// Use extra space
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