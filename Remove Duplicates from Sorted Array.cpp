class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
    
        if (n <= 0)
            return 0;
        
        for (int j = 1; j < n; j++) {
            if (A[i] < A[j]) {
                A[++i] = A[j];
            } 
        }
        
        return i + 1;
    }
};