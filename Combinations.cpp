// https://oj.leetcode.com/problems/combinations/

class Solution {
    void find_combine(vector<vector<int> > &ret, vector<int> &oneline, int begin, int n, int k) {
        if (k == 0) {
            ret.push_back(oneline);
            return;
        }
        
        for (int i = begin; i <= n - k + 1; i++) {
            oneline.push_back(i);
            find_combine(ret, oneline, i + 1, n, k - 1);
            oneline.pop_back();
        }
    }
    
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> oneline;
        
        if (n < k) {
            return ret;
        }
        find_combine(ret, oneline, 1, n, k);
        
        return ret;
    }
};