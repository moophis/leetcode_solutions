// https://oj.leetcode.com/problems/interleaving-string/

// Use DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();
        if (size3 != size1 + size2) {
            return false;
        }
        
        bool match[s1.size() + 1][s2.size() + 1];
        match[0][0] = true;
        for (int i = 1; i <= size1; i++) {
            match[i][0] = (match[i-1][0]) && (s1[i-1] == s3[i-1]);
        } 
        for (int j = 1; j <= size2; j++) {
            match[0][j] = (match[0][j-1]) && (s2[j-1] == s3[j-1]);
        }
        
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                match[i][j] = (match[i-1][j] && (s1[i-1] == s3[i+j-1])
                            || (match[i][j-1] && (s2[j-1] == s3[i+j-1])));
            }
        } 
        
        return match[size1][size2];
    }
};