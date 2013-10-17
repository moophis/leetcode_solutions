class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      // Note: The Solution object is instantiated only once and is reused by each test case.
      int beg, mid, end;
      beg = 0;
      end = n - 1;
      
      if (n == 0)
          return 0;
      while (beg <= end) { 
          mid = beg + (end - beg) / 2;
          if (target == A[mid])
              return mid;
          if (target < A[mid]) {
              end = mid - 1;
          } else {
              beg = mid + 1;
          }
      }
      
      return target > A[mid] ? mid + 1 : mid;
    }
};