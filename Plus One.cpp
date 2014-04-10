// http://oj.leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret(digits.size(), 0);
        int carry = 0;
        
        for (int i = digits.size() - 1; i >= 0; i--) {
            int d = digits[i];
            if (i == digits.size() - 1) {
                d++;
            }
            
            ret[i] = (d + carry) % 10;
            carry = (d + carry) / 10;
        }
        
        if (carry > 0) {
            auto it = ret.begin();
            ret.insert(it, carry);
        }
        
        return ret;
    }
};