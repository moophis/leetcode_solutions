// https://oj.leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        size_t len = s.size();
        size_t i = 0, j = len - 1;
        
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};