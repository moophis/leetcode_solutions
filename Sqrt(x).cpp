/**
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */
 
// binary seearch
class Solution {
public:
    int sqrt(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (x <= 0) {    // error case
            return 0;
        }
        
        long long low = 0, hi = x;
        
        
        while (low < hi) {
            long long mid = low + (hi - low + 1) / 2;
            if (mid * mid > (long long) x) {
                hi = mid - 1;
            } else {
                low = mid;
            }
        }
        
        return (int)low;
    }
};
