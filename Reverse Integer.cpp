// https://oj.leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        bool minus = (x < 0);
        if (minus) {
            x = -x;
        } 
        
        int ret = 0;
        while (x != 0) {
            int now = ret * 10 + (x % 10);
            if (now / 10 != ret) {
                return INT_MAX;  // overflow
            } else {
                ret = now;
            }
            
            x /= 10;
        }
        
        return minus ? -ret : ret;
    }
};