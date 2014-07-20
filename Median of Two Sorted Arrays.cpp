// https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Reference:
// http://blog.csdn.net/yutianzuijin/article/details/11499917

class Solution {
    // find the kth number from A[] and B[]
    double find_kth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return find_kth(B, n, A, m, k); 
        }
        if (m <= 0) {
            return B[k-1];
        }
        if (n <= 0) {
            return A[k-1];
        }
        if (k <= 1) {
            return min(A[0], B[0]);
        }
        
        int pa = min(k/2, m);
        int pb = k - pa;
        if (A[pa - 1] > B[pb - 1]) {
            return find_kth(A, m, B + pb, n - pb, k - pb);
        } else if (A[pa - 1] < B[pb - 1]) {
            return find_kth(A + pa, m - pa, B, n, k - pa);
        } else {
            return A[pa - 1];
        }
    }
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 0) {
            return (find_kth(A, m, B, n, (m+n)/2)
                    + find_kth(A, m, B, n, (m+n)/2 + 1)) / 2.0;
        } else {
            return find_kth(A, m, B, n, (m+n)/2 + 1);
        }
    }
};