// https://oj.leetcode.com/problems/palindrome-partitioning-ii/

// Use DP twice

class Solution {

public:
    int minCut(string s) {
        int len = s.size();
        if (len == 0) {
            return 0;
        }
        
        int cuts[len+1];
        bool pal[len][len];
        for (int i = 0; i <= len; i++) {
            cuts[i] = len - i - 1;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                pal[i][j] = false;
            }
        }
        
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] == s[j] && (j - i < 2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                    cuts[i] = min(cuts[i], cuts[j+1] + 1);
                }
            }
        }
        
        return cuts[0];
    }
};