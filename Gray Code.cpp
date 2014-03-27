// http://oj.leetcode.com/problems/gray-code/
// XXX: tricky!

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        
        if (n < 0) 
            return ret;
            
        int size = 1 << n;
        for (int i = 0; i < size; i++) {
            ret.push_back((i >> 1) ^ i);
        }
        
        return ret;
    }
};