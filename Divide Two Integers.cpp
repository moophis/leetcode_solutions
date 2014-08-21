// https://oj.leetcode.com/problems/divide-two-integers/
// Be careful about overflow when using abs()

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        
        long long dvd = dividend;
        long long dvs = divisor;
        dvd = abs(dvd);
        dvs = abs(dvs);
        int ret = 0;
        
        while (dvd >= dvs) {
            long long ds = dvs;
            for (int i = 1; dvd >= ds; ds <<= 1, i <<= 1) {
                ret += i;
                dvd -= ds;
            }
        }
        
        return ((dividend < 0) ^ (divisor < 0)) ? -ret : ret;
    }
};