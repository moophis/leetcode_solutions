class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *result = new int[n+1];   
              
        result[0] = 1;
        result[1] = 1;
        result[2] = 2;
        for (int i = 3; i <= n; i++) {
            result[i] = result[i-1] + result[i-2];
        }  
        
        int ret = result[n];
        delete []result;
        return ret;
    }
};