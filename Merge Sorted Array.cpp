/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B. 
 * The number of elements initialized in A and B are m and n respectively.
 */

// O(n) solution
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m <= 0 && n <= 0) {
            return;
        }
        
        int cur = m + n - 1;
        int i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[cur--] = A[i--];
            } else {
                A[cur--] = B[j--];
            }
        }
        while (j >= 0) {
            A[cur--] = B[j--];
        }
    }
};
 
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + i; j++) {
                if (B[i] < A[j]) {
                    swap(B[i], A[j]);
                }
            }
            swap(B[i], A[m + i]);
        }
    }
};