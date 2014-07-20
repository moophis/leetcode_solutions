// https://oj.leetcode.com/problems/roman-to-integer/
// Reference:
// http://fisherlei.blogspot.com/2012/12/leetcode-roman-to-integer.html

class Solution {
    int rc2i(char c) {
        switch (c) {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
            default : return 0;
        }
    }
public:
    int romanToInt(string s) {
        size_t size = s.size();
        if (size == 0) {
            return 0;
        }
        
        int value = 0;
        for (size_t i = 0; i < size; i++) {
            if (i > 0 && rc2i(s[i]) > rc2i(s[i-1])) {
                value += (rc2i(s[i]) - rc2i(s[i-1]) * 2);
            } else {
                value += rc2i(s[i]);
            }
        }
        
        return value;
    }
};