// http://oj.leetcode.com/problems/scramble-string/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) 
            return false;
        
        int size = s1.size();
        int alpha[26];
        memset(alpha, 0, 26 * sizeof(alpha[0]));
        
        for (int i = 0; i < size; i++) {
            alpha[s1[i]-'a']++;
        }
        for (int i = 0; i < size; i++) {
            alpha[s2[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != 0)
                return false;
        }
        
        if (size == 1)
            return true;
            
        for (int i = 1; i < size; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                    isScramble(s1.substr(i), s2.substr(i))) {
                return true;            
            }
            if (isScramble(s1.substr(0, i), s2.substr(size - i)) &&
                    isScramble(s1.substr(i), s2.substr(0, size - i))) {
                return true;            
            }
        }
        
        return false;
    }
};