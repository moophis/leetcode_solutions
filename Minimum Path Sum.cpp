/**
 * Given a m x n grid filled with non-negative numbers, find a path 
 * from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        
        if (m <= 0 || n <= 0) { // on error
            return -1;
        }
        
        vector<vector<int> > A(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = grid[i][j];
                if (i > 0 && j == 0) {
                    A[i][j] += A[i - 1][j];
                } else if (j > 0 && i == 0) {
                    A[i][j] += A[i][j - 1];
                } else if (i > 0 && j > 0) {
                    A[i][j] += min(A[i - 1][j], A[i][j - 1]);
                }
            }
        }
        
        return A[m - 1][n - 1];
    }
};