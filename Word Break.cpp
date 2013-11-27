/**
 * Given a string s and a dictionary of words dict, determine if s can 
 * be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * 
 * Return true because "leetcode" can be segmented as "leet code".
 */
 
/*
 * Use Dynamic Programming: set two indexes: i, j (j < i). 
 * If string(0, i) can be such string, string(0, j) must be such string,
 * and the string(j, i) must be such string. string(0, j) was previously
 * calculated, so this step we should only calculate string(j, i)
 *   ----------------------------------
 *   -      -    ?    -               -
 *   ----------------------------------
 *           ^         ^
 *           j         i 
 */
 
class Solution {
public:    
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (s.length() == 0) {
            return true;
        }
        
        bool dpbuf[s.length() + 1];
        memset(dpbuf, false, s.length() + 1);
        
        dpbuf[0] = true;
        for (size_t i = 1; i <= s.length(); i++) {
            for (size_t j = 0; j < i; j++) {
                if (dpbuf[j] && dict.count(s.substr(j, i - j)) > 0) {
                    dpbuf[i] = true;
                }
            }
        }
        
        return dpbuf[s.length()];
    }
};