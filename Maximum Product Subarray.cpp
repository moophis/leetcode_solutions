// https://oj.leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        
        int max_ending_here = A[0];
        int min_ending_here = A[0];
        int maxval = A[0];
        
        for (int i = 1; i < n; i++) {
            int last_max = max_ending_here;
            int last_min = min_ending_here;
            if (A[i] == 0) {
                max_ending_here = 0;
                min_ending_here = 0;
            } else if (A[i] > 0) {
                max_ending_here = max(A[i] * last_max, A[i]);
                min_ending_here = min(A[i] * last_min, A[i]);
            } else {
                max_ending_here = max(A[i] * last_min, A[i]);
                min_ending_here = min(A[i] * last_max, A[i]);
            }
            
            if (max_ending_here > maxval) {
                maxval = max_ending_here;
            }
        }
        
        return maxval;
    }
};