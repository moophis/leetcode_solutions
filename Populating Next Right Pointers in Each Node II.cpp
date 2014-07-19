// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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