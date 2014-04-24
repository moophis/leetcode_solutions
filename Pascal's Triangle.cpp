// http://oj.leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        
        if (numRows <= 0) {
            return ret;
        }
        
        ret.push_back({1});
        if (numRows == 1) {
            return ret;
        }
        ret.push_back({1, 1});
        if (numRows == 2) {
            return ret;
        }
        
        for (int i = 2; i < numRows; i++) {
            vector<int> line;
            
            line.push_back(1);
            for (int j = 1; j < i; j++) {
                line.push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            line.push_back(1);
            ret.push_back(line);
        }
        
        return ret;
    }
};