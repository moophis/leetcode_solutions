// https://oj.leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        
        int start = 0;
        int end = 0;
        int steps = 0;
        
        while (end < n) {
            int maxplace = 0;
            bool zero = true;
            
            steps++;
            for (int i = start; i <= end; i++) {
                if (A[i] != 0) {
                    zero = false;
                }
                maxplace = max(maxplace, A[i] + i);
                if (maxplace >= n - 1) {
                    return steps;
                }
            }
            if (zero) {
                return INT_MAX;  // no solution
            }
            
            start = end + 1;
            end = maxplace;
        }
        
        return steps;
    }
};