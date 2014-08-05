// https://oj.leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int size = static_cast<int>(matrix.size());
        if (size < 2) {
            return;
        }
        
        for (int i = 0; i < size / 2; i++) {
            for (int j = i; j - i < cur_size - 1; j++) {
                int cache = matrix[i][j];
                int n = j, m = i;
                for (int k = 0; k < 4; k++) {
                    int row = n;
                    int col = size - 1 - m;
                    int tmp = matrix[row][col];
                    matrix[row][col] = cache;
                    cache = tmp;
                    m = row;
                    n = col;
                }
            }
        }
    }
};