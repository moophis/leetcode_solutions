// https://oj.leetcode.com/problems/powx-n/

class Solution {
public:
    double pow(double x, int n) {
    	// not a number
        volatile double t = x;
        if (t != t) {
            return x;
        }
        
        if (x == 1.0) {
            return 1.0;
        } else if (x == -1.0) {
            return (n % 2 == 0) ? 1.0: -1.0; 
        }

        double result = 1.0;
        if (n < 0) {
            n = -n;
            while (n-- > 0) {
                result = result / x;
                if (abs(result) < numeric_limits<double>::epsilon()) {
                    return 0.0;
                }
            }
        } else {
            while (n-- > 0) {
                result = result * x;
                if (abs(result) < numeric_limits<double>::epsilon()) {
                    return 0.0;
                }
            }
        }
        return result;
    }
};