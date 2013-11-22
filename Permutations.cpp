/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        
        if (num.size() == 0)
            return ret;
        
        do_permute(ret, num);
        return ret;
    }
    
    void do_permute(vector<vector<int> > &ret, vector<int> &num) {
        static vector<int> buf;
        int n = num.size();
        
        if (n == 0) {    // base case
            ret.push_back(buf);
            return;
        }
        for (int i = 0; i < n; i++) {
            int t = num[i];
            
            buf.push_back(t);
            swap(num[i], num[n - 1]);
            num.pop_back();   
            do_permute(ret, num);
            num.push_back(t);
            swap(num[i], num[n - 1]);
            buf.pop_back();
        }
        
    }
};