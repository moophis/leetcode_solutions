// https://oj.leetcode.com/problems/spiral-matrix-ii/

class Solution {
    void fill(vector<vector<int> > &matrix, int row_from, int row_to,
            int col_from, int col_to, int start_val) {
        if (row_from > row_to || col_from > col_to) {
            return;
        }         
        
        // go right
        for (int i = col_from; i <= col_to; i++) {
            matrix[row_from][i] = start_val++;
        }    
        // go down 
        for (int i = row_from + 1; i <= row_to; i++) {
            matrix[i][col_to] = start_val++;
        }
        // go left
        if (row_from < row_to) {
            for (int i = col_to - 1; i >= col_from; i--) {
                matrix[row_to][i] = start_val++;
            }
        }
        // go up
        if (col_from < col_to) {
            for (int i = row_to - 1; i > row_from; i--) {
                matrix[i][col_from] = start_val++;
            }
        }
        
        fill(matrix, row_from + 1, row_to - 1, col_from + 1, col_to - 1, start_val);
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> row(n);
        vector<vector<int> > ret(n, row);
    
        if (n <= 0) {
            return ret;
        }
        
        fill(ret, 0, n - 1, 0, n - 1, 1);
        return ret;
    }
};