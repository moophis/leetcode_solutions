/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */

class Solution {
    void do_permute(vector<int> &num, vector<vector<int> > &ret, vector<int> &line, int n) {
        if (n == 0) {
            ret.push_back(line);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            line.push_back(num[i]);
            swap(num[i], num[n-1]);
            do_permute(num, ret, line, n - 1);
            swap(num[i], num[n-1]);
            line.pop_back();
        }
    }

public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        int size = num.size();
        if (size == 0) {
            return ret;
        }
        
        vector<int> line;
        do_permute(num, ret, line, size);
        
        return ret;
    }
};