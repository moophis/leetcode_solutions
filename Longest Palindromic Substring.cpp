/**
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there 
 * exists one unique longest palindromic substring.
 */
 
// O(n^2) solution
class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.size();
        bool is_pal[N][N];
        int maxlen = 1;
        int max_start = 0;
        
        // initialization: substring from i to j
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i >= j) {  // i > j: empty substring
                    is_pal[i][j] = true;
                } else {
                    is_pal[i][j] = false;
                }
            }
        }
        
        for (int k = 1; k < N; k++) {    // k: stride
            for (int i = 0; i + k < N; i++) {
                int j = i + k;
                is_pal[i][j] = (s[i] == s[j]) && is_pal[i + 1][j - 1]; 
                if (is_pal[i][j]) {
                    if (k + 1 > maxlen) {
                        maxlen = k + 1;
                        max_start = i;
                    }
                }
            }
        }
        
        return s.substr(max_start, maxlen);
    }
};