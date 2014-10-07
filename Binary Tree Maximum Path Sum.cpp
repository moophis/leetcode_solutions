/**
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *
 *      1
 *     / \
 *    2   3
 * Return 6.
 */
 
// Simplified version
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
    int find_max(TreeNode *root, int &cur_max) {
        if (root == nullptr) {
            return 0;
        }

        int left_single = find_max(root->left, cur_max);
        int right_single = find_max(root->right, cur_max);
        int single = max(0, max(left_single, right_single)) + root->val;
        int crossing = left_single + right_single + root->val;
        cur_max = max(cur_max, max(single, crossing));
        
        return single;  // return max single path
    }
    
public:
    int maxPathSum(TreeNode *root) {
        int cur_max = INT_MIN;
        find_max(root, cur_max);
        
        return cur_max;
    }
};

/*
 * This this a really tricky one:
 * The maximum path for each sub-tree can be either:
 * 1) The single path starting downward from the root; or
 * 2) The path either traversing from left child nodes to the root
 *    then to the right child nodes, or only containing left or
 *    right child nodes. (We call this detached path)
 * So if we want to find out the maximum path sum, we can recursively
 * find the maximum sum of either those aforementioned two cases, and
 * return the maximum of them. And do not forget the history detached
 * path.
 */
class Solution {
    struct ret {
        int maxlen;       // maximum path sum for case 1)
        int detached_max; // maximum path sum for case 2)
        bool detached;    // whether case 2) has larger sum
    };
    
    struct ret find_max(TreeNode *root) {
        const int MIN = numeric_limits<int>::min();
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, MIN, false};
        }
        
        int max_len = MIN;
        int detached_max_len = MIN;
        struct ret left_ret = {MIN, MIN, false};
        struct ret right_ret = {MIN, MIN, false};
        struct ret cur_ret = {MIN, MIN, false};
        
        // recursively find max and the detached max
        if (root->left != nullptr) {
            left_ret = find_max(root->left);
        } 
        if (root->right != nullptr) {
            right_ret = find_max(root->right);
        }
        
        max_len = max(left_ret.maxlen, right_ret.maxlen);
        
        // calculate as if this path can be used by parent nodes
        cur_ret.maxlen = max(root->val + max_len, root->val);
        
        // check whether the current max path can be independent to parent nodes
        if (left_ret.maxlen == MIN || right_ret.maxlen == MIN) {
            // detached: left or right
            cur_ret.detached_max = max_len;
        } else {
            // detached: left->cur->right
            cur_ret.detached_max = max(max_len, 
                                   left_ret.maxlen + right_ret.maxlen + root->val);
        }
        // check which detached path is larger: current node's or children's?
        if (left_ret.detached || right_ret.detached) { // check out history
            detached_max_len = max(left_ret.detached_max, 
                                   right_ret.detached_max);
        }
        cur_ret.detached_max = max(cur_ret.detached_max, detached_max_len);
        
        // whether the dependent sum is no smaller than detached sum
        if (cur_ret.detached_max > cur_ret.maxlen) {
            cur_ret.detached = true;
        } else {
            cur_ret.detached = false;
        }
        
        return cur_ret;
    }
    
public:
    int maxPathSum(TreeNode *root) {
        int maxlen = numeric_limits<int>::min();
        if (root == nullptr) {  // error case
            return maxlen;
        }
        
        struct ret r = find_max(root);
        
        return r.detached ? r.detached_max : r.maxlen;
    }
};