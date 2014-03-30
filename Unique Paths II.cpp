// http://oj.leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m <= 0) {
            return 0;
        }
        
        int n = obstacleGrid[0].size();
        if (n <= 0) {
            return 0;
        }
        
        int arr[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = 0;
            }
        }
        
        arr[m - 1][n - 1] = obstacleGrid[m - 1][n - 1] == 1 ? 0 : 1;
        for (int i = m - 2; i >= 0; i--) {
            if (obstacleGrid[i][n - 1] == 0)
                arr[i][n - 1] = arr[i + 1][n - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            if (obstacleGrid[m - 1][i] == 0)
                arr[m - 1][i] = arr[m - 1][i + 1];
        }
        
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (obstacleGrid[i][j] == 0) {
                    arr[i][j] = arr[i][j + 1] + arr[i + 1][j];
                } else {
                    arr[i][j] = 0;
                }
            }
        }
        
        return arr[0][0];
    }
};