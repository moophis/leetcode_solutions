// http://oj.leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        
        if (rowIndex < 0) {
            return ret;
        }
        if (rowIndex == 0) {
            ret.push_back(1);
            return ret;
        }
        if (rowIndex == 1) {
            ret.push_back(1);
            ret.push_back(1);
            return ret;
        }
        
        vector<int> last({1, 1});
        for (int i = 2; i <= rowIndex; i++) {
            ret.push_back(1);
            for (int j = 1; j < i; j++) {
                ret.push_back(last[j-1] + last[j]);
            }
            ret.push_back(1);
            
            if (i != rowIndex) {
                last = ret;
                ret.clear();
            }         
        }
        
        return ret;
    }
};