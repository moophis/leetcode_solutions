// https://oj.leetcode.com/problems/edit-distance/

/**
 * Use dynamic programming
 */
 class Solution {    
public:
    int minDistance(string word1, string word2) {
        size_t size1 = word1.size();
        size_t size2 = word2.size();
        if (size1 == 0) {
            return (int) size2;
        }
        if (size2 == 0) {
            return (int) size1;
        }
        
        size_t cost[size1+1][size2+1];
        for (size_t i = 0; i <= size1; i++) {
            for (size_t j = 0; j <= size2; j++) {
                cost[i][j] = 0;
            }
        }
        for (size_t i = 0; i <= size1; i++) {
            cost[i][0] = i;
        }
        for (size_t i = 0; i <= size2; i++) {
            cost[0][i] = i;
        }
        
        for (size_t i = 1; i <= size1; i++) {
            for (size_t j = 1; j <= size2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    cost[i][j] = cost[i-1][j-1];
                } else {
                    cost[i][j] = 1 + min(min(cost[i-1][j], cost[i][j-1]), cost[i-1][j-1]);
                }
            }
        } 
        
        return (int) cost[size1][size2];
    }
};