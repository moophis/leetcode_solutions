// https://oj.leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int M = matrix.size();
        if (M == 0) return;
        int N = matrix[0].size();
        if (N == 0) return;
        
        int ref_row = -1;
        int ref_col = -1;
        bool has_zero = false;
        
        // mark rows and columns containing zero
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 0) {
                    if (!has_zero) {
                        has_zero = true;
                        ref_row = i;
                        ref_col = j;   
                    } 
                    matrix[ref_row][j] = 0;
                    matrix[i][ref_col] = 0;
                }
            }
        }
        
        if (!has_zero) return;
        
        // clear those rows and columns
        for (int i = 0; i < M; i++) {
            if (matrix[i][ref_col] == 0 && i != ref_row) {
                for (int j = 0; j < N; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < N; j++) {
            if (matrix[ref_row][j] == 0) {
                for (int i = 0; i < M; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // clear ref row
        for (int j = 0; j < N; j++) {
            matrix[ref_row][j] = 0;
        }
    }
};