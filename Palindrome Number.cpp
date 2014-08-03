// https://oj.leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        // In case of overflow
        long long base = 1;
        while (x / (base * 10) > 0) {
            base = base * 10;
        }
        
        for (long long i = base, j = 1; i >= j; i /= 10, j *= 10) {
            if ((x / i) % 10 != (x / j) % 10) {
                return false;
            }
        }
        
        return true;
    }
};