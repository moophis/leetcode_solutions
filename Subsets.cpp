// https://oj.leetcode.com/problems/subsets/

// Bit manipulation
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int size = static_cast<int>(S.size());
        vector<vector<int> > ret;
        vector<int> tmp;
        if (size <= 0 || size > 32) {
            return ret;
        }
        
        int bit = 0;  // assume size of set will not exceed 32
        int MAX_MASK = (1 << size);
        while ((bit & MAX_MASK) == 0) {
            for (int i = size - 1; i >= 0; i--) {
                if (bit & (1 << i)) {
                    tmp.push_back(S[i]);
                }
            }
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
            tmp.clear();
            
            bit++;
        }
        
        return ret;
    }
};

// Iteration
// http://www.cnblogs.com/TenosDoIt/p/3451902.html
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int size = static_cast<int>(S.size());
        vector<vector<int> > ret;
        
        sort(S.begin(), S.end());
        
        ret.push_back({});  
        for (int i = 0; i < size; i++) {
             int retsize = ret.size();
             for (int j = 0; j < retsize; j++) {
                 vector<int> t = ret[j];
                 t.push_back(S[i]);
                 ret.push_back(t);
             }
        }
        
        return ret;
    }
};


// Recursion
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
