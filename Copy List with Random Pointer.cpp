// http://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// iterative
class Solution {
public:
    RandomListNode *generate(unordered_map<RandomListNode *, RandomListNode *> &copied, RandomListNode *old) {
        RandomListNode *node;
        if (copied.count(old) == 0) {
            node = new RandomListNode(old->label);
            copied.emplace(old, node);
        } else {
            node = copied[old];
        }
        return node; 
    } 
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        unordered_map<RandomListNode *, RandomListNode *> copied;
        RandomListNode *cur = head;
        RandomListNode *new_head = new RandomListNode(head->label);
        RandomListNode *new_cur = new_head;
        while (cur != nullptr) {
            if (cur->next != nullptr) {
                new_cur->next = generate(copied, cur->next);
            }
            if (cur->random != nullptr) {
                new_cur->random = generate(copied, cur->random);
            }
            cur = cur->next;
            new_cur = new_cur->next;
        }
        
        return new_head;
    }
};

// recursion
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