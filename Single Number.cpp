class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i = 0; i < n - 1; i++) {
            A[i+1] ^= A[i]; 
        }
    
        return A[n-1];
    }
};