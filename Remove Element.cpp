/* By swapping: ugly */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i, j;
    
        if (n <= 0)
            return 0;
            
        for (i = 0, j = n-1; i <= j; i++) {
            while (A[j] == elem)
                j--;
            while (A[i] == elem && i < j) {
                swap(A[i], A[j--]); 
            }
            if (A[i] == elem)
                return i;
        }
        
        return i;
    }
};

// For better swapping solution, refer to
// http://yingying-zheng.com/?p=275