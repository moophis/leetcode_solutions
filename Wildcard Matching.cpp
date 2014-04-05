// http://oj.leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int cur_s = 0;
        int cur_p = 0;
        int len_s = strlen(s);
        int len_p = strlen(p);
        int last_p = 0;   // important
        int last_s = 0;   // for backtrack
        bool handled_star = false;
        
        while (cur_s < len_s) {
            switch (p[cur_p]) {
            case '?':
                cur_p++;
                cur_s++;
                break;
            case '*':
                while (cur_p < len_p && p[cur_p] == '*')
                    cur_p++;
                if (cur_p == len_p)
                    return true;
                last_p = cur_p;
                last_s = cur_s;
                handled_star = true;
                break;
            default:
                if (s[cur_s] == p[cur_p]) {
                    cur_s++;
                    cur_p++;
                } else {
                    if (!handled_star) {
                        return false;
                    } else {
                        // backtrack: when we cannot find a match after a '*',
                        // we should just extend the range this '*' covers by 1
                        cur_p = last_p;
                        cur_s = ++last_s;
                    }
                }
            }
        }
        
        while (cur_p < len_p) {
            if (p[cur_p++] != '*')
                return false;
        }
        return true;
    }
};