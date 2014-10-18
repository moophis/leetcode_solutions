// https://oj.leetcode.com/problems/single-number/

// Binary search, O(nlogn) for sorting, O(logn) for searching.
// It's especially useful when the array is sorted.
// Idea: the odd-even property of starting index of the same numbers
// can be different from whether the single number is ahead of them.
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n % 2 == 0) {
            return INT_MIN;
        }
        
        sort(A, A + n);
        
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == 0 || mid == n - 1) {
                return A[mid];
            } else if (A[mid] > A[mid-1] && A[mid] < A[mid+1]) {
                return A[mid];
            } else { 
                if (mid % 2 == 0) { 
                    if (A[mid] == A[mid+1]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }   
                } else {
                    if (A[mid] == A[mid+1]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
            }
        }
        
        return INT_MIN;  // cannot find
    }
};

// Bit manipulation: O(n), can be used in unsorted array
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