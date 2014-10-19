// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// Iterative solution: use O(1) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        
        TreeLinkNode *cur = root;      // node in the current level
        TreeLinkNode *head = nullptr;  // the first node in the next level
        TreeLinkNode *prev = nullptr;  // the node by which the current processed node is pointed
        
        while (cur != nullptr) {
            while (cur != nullptr) {
                if (cur->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                if (cur->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                cur = cur->next;
            }
            
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
    }
};

// Recursion: still use O(n) extra space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
        
        // assemble right
        if (root->right != nullptr) {
            for (TreeLinkNode *nd = root->next; nd != nullptr; nd = nd->next) {
                if (nd->left != nullptr) {
                    root->right->next = nd->left;
                    break;
                } else if (nd->right != nullptr) {
                    root->right->next = nd->right;
                    break;
                }
            }
            connect(root->right);
        }
        
        // assemble left
        if (root->left != nullptr) {
            if (root->right != nullptr) {
                root->left->next = root->right;
            } else {
                for (TreeLinkNode *nd = root->next; nd != nullptr; nd = nd->next) {
                    if (nd->left != nullptr) {
                        root->left->next = nd->left;
                        break;
                    } else if (nd->right != nullptr) {
                        root->left->next = nd->right;
                        break;
                    }
                }
            }
            connect(root->left);
        }
    }
};