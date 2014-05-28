// https://oj.leetcode.com/problems/word-ladder/

// Use BFS to find the length of the minimum path.
// Note: we should use the very fact that every character in the
// string ranges from 'a' to 'z' so that we can enumerate and test 
// all possibilities for the next character change.

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size() || dict.size() == 0) {
            return 0;
        }
        
        const size_t wordlen = start.size();
        queue<string> q1, q2;
        queue<string> *q = &q1;
        queue<string> *nextq = &q2;
        int level = 1;
                
        q->push(start);
        while (!q->empty()) {
            string cur = q->front();
            q->pop();
            
            if (cur.size() != wordlen) {
                return 0;
            }
            
            for (size_t i = 0; i < cur.size(); i++) {
                for (int j = 'a'; j <= 'z'; j++) {
                    char tmp = cur[i];
                    if (j == cur[i]) {
                        continue;
                    }
                    cur[i] = j;
                    if (cur.compare(end) == 0) {
                        return level + 1;
                    }
                    if (dict.count(cur) > 0) {
                        nextq->push(cur);
                        dict.erase(cur);
                    }
                    cur[i] = tmp;
                }
            }
                        
            if (q->empty()) {
                level++;
                queue<string> *t = q;
                q = nextq;
                nextq = t;
            }
        }
        
        return 0;
    }
}; 