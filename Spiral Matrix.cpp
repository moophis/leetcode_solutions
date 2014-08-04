// https://oj.leetcode.com/problems/spiral-matrix/

class Solution {
    void find_order(vector<vector<int> > &matrix, vector<int> &ret, 
        int row_from, int row_to, int col_from, int col_to) {
        if (row_from > row_to || col_from > col_to) {
            return;
        } 
        
        // go right
        for (int i = col_from; i <= col_to; i++) {
            ret.push_back(matrix[row_from][i]);
        }    
        // go down 
        for (int i = row_from + 1; i <= row_to; i++) {
            ret.push_back(matrix[i][col_to]);
        }
        // go left
        if (row_from < row_to) {
            for (int i = col_to - 1; i >= col_from; i--) {
                ret.push_back(matrix[row_to][i]);
            }
        }
        // go up
        if (col_from < col_to) {
            for (int i = row_to - 1; i > row_from; i--) {
                ret.push_back(matrix[i][col_from]);
            }
        }
        
        find_order(matrix, ret, row_from + 1, row_to - 1, col_from + 1, col_to - 1);
    }
    
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.size() == 0) {
            return ret;
        }
        
        int m = matrix.size(), n = matrix[0].size();
        find_order(matrix, ret, 0, m - 1, 0, n - 1);
        
        return ret;
    }
};