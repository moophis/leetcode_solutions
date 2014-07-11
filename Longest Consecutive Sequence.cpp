// https://oj.leetcode.com/problems/longest-consecutive-sequence/

// Use hash set
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() <= 1) {
            return static_cast<int>(num.size());
        }
        
        int maxlen = 1;
        unordered_set<int> nset;
        for (auto it = num.begin(); it != num.end(); ++it) {
            nset.emplace(*it);
        }
        
        while (nset.size() > 0) {
            int cur = *(nset.begin());
            int lo = cur;
            int hi = cur;
            
            for (int i = cur; nset.count(i) > 0; i--) {
                lo = i;
            }  
            for (int i = cur; nset.count(i) > 0; i++) {
                hi = i;
            }
            maxlen = max(maxlen, hi - lo + 1);
            
            // remove current consecutive numbers from the set
            for (int i = lo; i <= hi; i++) {
                nset.erase(i);
            }
        }
        
        return maxlen;
    }
};