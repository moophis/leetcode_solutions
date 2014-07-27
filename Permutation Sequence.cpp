// https://oj.leetcode.com/problems/permutation-sequence/

class Solution {
    inline int factorial(int n) {
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
    }
    
public:
    string getPermutation(int n, int k) {
        if (n <= 0 || n > 9 || k <= 0 || k > factorial(n)) {
            return "";
        }
        
        vector<string> nums {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
        string ret = "";
        for (int i = n; i >= 1; i--) {
            int f = factorial(i-1);
            int c = (k-1) / f;
            
            string digit = nums[c];
            nums.erase(nums.begin() + c);

            ret += digit;
            k = k - f * c; 
        } 
        
        return ret;
    }
};