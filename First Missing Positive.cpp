// https://oj.leetcode.com/problems/first-missing-positive/

// Coordinate each existing positive number in its "right" slot
// (i.e. 1 in slot 0, 10 in slot 9) and find the missing one by
// checking discrepancy in the array.
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n <= 0) {
            return 1;
        }
        
        for (int i = 0; i < n; i++) {
            int digit = A[i];
            while (digit > 0 && digit <= n && A[digit-1] != digit) {
                swap(A[digit-1], A[i]);
                digit = A[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};