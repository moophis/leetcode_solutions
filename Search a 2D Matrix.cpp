// https://oj.leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int M = matrix.size();
        if (M == 0) {
            return false;
        }
        int N = matrix[0].size();
        
        int beg = 0, end = M - 1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][N-1]) {
                // search the current row
                int cbeg = 0, cend = N - 1;
                while (cbeg <= cend) {
                    int cmid = cbeg + (cend - cbeg) / 2;
                    if (target == matrix[mid][cmid]) {
                        return true;
                    } else if (target > matrix[mid][cmid]) {
                        cbeg = cmid + 1;
                    } else {  // target < matrix[mid][cmid]
                        cend = cmid - 1;
                    }
                }
                return false;
            } else if (target >= matrix[mid][N-1]) {
                beg = mid + 1;
            } else { // target < matrix[mid][0]
                end = mid - 1;
            }
        }
        
        return false;
    }
};