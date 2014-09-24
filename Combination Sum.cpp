// https://oj.leetcode.com/problems/combination-sum/

class Solution {
    void do_combination(vector<int> &candidates, int &sum, int target, int begin,
                        vector<vector<int> > &ret, vector<int> &one_result) {
        if (target == sum) {
            ret.push_back(one_result);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = begin; i < candidates.size(); i++) {
            one_result.push_back(candidates[i]);
            sum += candidates[i];
            do_combination(candidates, sum, target, i, ret, one_result);
            sum -= candidates[i];
            one_result.pop_back();
        }
    }
    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> one;
        int sum = 0;
        
        sort(candidates.begin(), candidates.end());
        do_combination(candidates, sum, target, 0, ret, one);
        return ret;
    }
};