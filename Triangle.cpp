// https://oj.leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        size_t size = triangle.size();
        
        if (size == 0) {
            return 0;
        }
        
        for (size_t i = size - 1; i > 0; i--) {
            for (size_t j = 0; j < triangle[i].size() - 1; j++) {
                triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};