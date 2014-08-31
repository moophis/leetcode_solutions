// https://oj.leetcode.com/problems/search-for-a-range/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret = {-1, -1};
        if (n == 0 || target < A[0] || target > A[n-1]) {
            return ret;
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] == target) {
                if (ret[0] == -1) {
                    ret[0] = i;
                }
            } else if (A[i] > target) {
                if (ret[1] == -1 && ret[0] != -1) {
                    ret[1] = i - 1;
                }
                break;
            }
        }
        if (ret[1] == -1 && ret[0] != -1) {
            ret[1] = n - 1;
        }
        
        return ret;
    }
};