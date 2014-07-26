// https://oj.leetcode.com/problems/distinct-subsequences/
// Reference:
// http://fisherlei.blogspot.com/2012/12/leetcode-distinct-subsequences_19.html

class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.size() == 0) {
            return 0;
        }
        if (T.size() == 0) {
            return 1;
        }
        
        int opt[T.size() + 1];
        for (size_t i = 0; i <= T.size(); i++) {
            opt[i] = 0;
        } 
        /*
         * Initial step: if S[0] == T[0]:
         * opt[1] += opt[0]
         */
        opt[0] = 1;
        for (size_t i = 1; i <= S.size(); i++) {
            for (size_t j = T.size(); j >= 1; j--) {
                if (S[i-1] == T[j-1]) {
                    opt[j] += opt[j-1];                     
                } 
            }
        }
        
        return opt[T.size()];
    }
};
