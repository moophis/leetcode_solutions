// http://oj.leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == nullptr || p == nullptr || *p == '*') {
            return false;
        }
        if (*p == '\0') {
            return *s == '\0';
        } 
        
        if (*(p+1) == '\0' || *(p+1) != '*') { // do not have tailing '*'
            if (*s == '\0') {
                return false;
            }
            return (*s == *p || *p == '.') ? isMatch(s+1, p+1) : false;
        } else { // now deal with '*'
            if (isMatch(s, p+2)) { // '*' matches nothing
                return true;
            }
            int slen = strlen(s);
            for (int i = 0; i < slen; i++) {
                if (*p != '.' && *p != *(s+i)) { 
                    return false;
                }
                if (isMatch(s+i+1, p+2)) {
                    return true;
                }
            }
            return false;
        }
    }
};
