// https://oj.leetcode.com/problems/maximum-subarray/

// O(n) solution
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        
        int maxval = A[0];
        int cur_max = A[0];
        for (int i = 1; i < n; i++) {
            cur_max = max(A[i], A[i] + cur_max);
            maxval = max(maxval, cur_max);
        }
        
        return maxval;
    }
};

// O(nlog(n)): divide and conquer
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return A[0];
        }
        
        int mid = n >> 1;
        int left_sum = maxSubArray(A, mid);
        int right_sum = maxSubArray(A + mid, n - mid);
        
        int sum = 0;
        int lmid_sum = INT_MIN;
        int rmid_sum = INT_MIN;
        for (int i = mid - 1; i >= 0; i--) {
            sum += A[i];
            lmid_sum = max(sum, lmid_sum);
        }
        sum = 0;
        for (int i = mid; i < n; i++) {
            sum += A[i];
            rmid_sum = max(sum, rmid_sum);
        }
        
        return max(lmid_sum + rmid_sum, max(left_sum, right_sum));
    }
};