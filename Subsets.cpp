// https://oj.leetcode.com/problems/subsets/

class Solution {
    void subsets_of(int n, vector<int> &S, int start, const int size,
                    vector<vector<int> > &result, vector<int> &one_result) {
        if (n == 0) {
            result.push_back(one_result);
            return;
        }
        
        for (int i = start; i < size; i++) {
            one_result.push_back(S[i]);
            subsets_of(n - 1, S, i + 1, size, result, one_result);
            one_result.pop_back();
        }
    }
    
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int size = static_cast<int>(S.size());
        vector<vector<int> > ret;
        vector<int> tmp;
        
        sort(S.begin(), S.end());
        for (int i = 0; i <= size; i++) {
            subsets_of(i, S, 0, size, ret, tmp);
        }
        
        return ret;
    }
};
