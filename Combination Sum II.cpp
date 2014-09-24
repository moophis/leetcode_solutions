// https://oj.leetcode.com/problems/combination-sum-ii/

class Solution {
    void do_combination(vector<int> &candidates, int &sum, int target, int begin,
                        vector<vector<int> > &ret, vector<int> &one_result) {
        if (target == sum) {
            ret.push_back(one_result);
            return;
        } else if (sum > target) {
            return;
        }
        
        int last = INT_MIN;
        for (int i = begin; i < candidates.size(); i++) {
            if (last == candidates[i]) {
                continue;
            } else {
                last = candidates[i];
            }
            one_result.push_back(candidates[i]);
            sum += candidates[i];
            do_combination(candidates, sum, target, i + 1, ret, one_result);
            sum -= candidates[i];
            one_result.pop_back();
        }
    }
    
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> one;
        int sum = 0;
        
        sort(num.begin(), num.end());
        do_combination(num, sum, target, 0, ret, one);
        return ret;        
    }
};