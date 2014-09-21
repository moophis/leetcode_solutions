// https://oj.leetcode.com/problems/valid-number/

class Solution {
public:
    bool isNumber(const char *s) {
        if (*s == 0) {
            return false;
        } 
        
        bool last_digit = false;
        bool has_exp = false;
        bool has_dot = false;
        while (*s != 0 && *s == ' ') { // heading whitespace
            s++;
        }
        if (*s == '+' || *s == '-') { // heading sign
            s++;
        }
        if (*s == '.') {
            s++;
            has_dot = true;
        }
        
        int len = strlen(s);
        int newlen = 0;
        for (int i = len - 1; i >= 0; i--) { // tailing whitespace
            if (s[i] != ' ') {
                newlen = i + 1;
                break;
            }
        }
        if (newlen == 0) {
            return false;
        }
        
        for (int i = 0; i < newlen; i++) {
            char c = s[i];
            if (isdigit(c)) {
                last_digit = true;
            } else if (c == '.') {
                if (has_dot || has_exp || !last_digit) {
                    return false;
                } 
                has_dot = true;
            } else if (c == '+' || c == '-') {
                if (i == 0 || (s[i-1] != 'E' && s[i-1] != 'e') || i == newlen - 1) {
                    return false;
                }
                last_digit = false;
            } else if (c == 'E' || c == 'e') {
                if (has_exp || !last_digit || i == newlen - 1) {
                    return false;
                }
                has_exp = true;
                last_digit = false;
            } else {
                return false;
            }
        }
        
        return true;
    }
};