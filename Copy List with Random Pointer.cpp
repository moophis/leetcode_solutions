// http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    unordered_map<int, RandomListNode *> copied;
    
    void copy(RandomListNode* &from, RandomListNode* &to) {
        if (from == nullptr) {
            return;
        }
        
        if (to == nullptr) {
            int lb = from->label;
            if (copied.count(lb) == 0) {
                to = new RandomListNode(lb);
                copied.emplace(lb, to);
            } else {
                to = copied[lb];
            }
            
            copy(from->next, to->next);
            copy(from->random, to->random);
        }
    }
    
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *new_head = nullptr;
        
        copy(head, new_head);
        return new_head;
    }
};