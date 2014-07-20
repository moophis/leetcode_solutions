// https://oj.leetcode.com/problems/integer-to-roman/
// Reference:
// http://fisherlei.blogspot.com/2012/12/leetcode-integer-to-roman.html

class Solution {
public:
    string intToRoman(int num) {
        char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string ret;
        int base = 1000;
        
        for (int i = 6; i >= 0; i = i - 2) {
            int digit = num / base;
            
            if (digit != 0) {
                if (digit <= 3) {
                    ret.append(digit, symbol[i]);
                } else if (digit == 4) {
                    ret.append(1, symbol[i]);
                    ret.append(1, symbol[i+1]);
                } else if (digit == 5) {
                    ret.append(1, symbol[i+1]);
                } else if (digit <= 8) {
                    ret.append(1, symbol[i+1]);
                    ret.append(digit - 5, symbol[i]);
                } else if (digit == 9) {
                    ret.append(1, symbol[i]);
                    ret.append(1, symbol[i+2]);
                }
            }
            num = num % base;
            base = base / 10;
        }
        
        return ret;
    }
};