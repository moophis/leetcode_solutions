// https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(int A[], int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (A[m] == target) {
                return m;
            }
            // should be >= instead of > because the index of median is always rounded down
            if (A[m] >= A[l]) {  
                if (target < A[m] && target >= A[l]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (target > A[m] && target <= A[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};