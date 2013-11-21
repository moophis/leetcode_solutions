/**
 * Given an array of non-negative integers, you are 
 * initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump 
 * length at that position.
 *
 * Determine if you are able to reach the last index.
 *
 * For example:
 * A = [2,3,1,1,4], return true.
 *
 * A = [3,2,1,0,4], return false.
 */
 
class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int smax = 0;
        
        for (int i = 0; i < n - 1; i++) {
            // Should really care about the levels from which we cannot jump
            if (A[i] == 0 && smax <= i)
                return false;
            // If at step i we can jump maximum steps among
            // level 0, 1, ..., i, we choose jump from this level
            smax = max(i + A[i], smax);
        }
        
        return smax >= n - 1;
    }
};