// https://oj.leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == nullptr) {
            return 0;
        }
        
        bool is_first = true;
        int cnt = 0;
        while (*s != '\0') {
            if (*s == ' ') {
                is_first = true;
            } else {
                cnt = is_first ? 1 : cnt + 1;
                is_first = false;
            }
            s++;
        }        
        
        return cnt;
    }
};