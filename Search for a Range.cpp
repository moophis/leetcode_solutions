// https://oj.leetcode.com/problems/search-for-a-range/

// O(logn): use binary search three times
class Solution {
    int find_upper(int A[], int from, int to, int target) {
        while (from <= to) {
            int mid = from + (to - from) / 2;
            
            if (A[mid] == target) {
                if (mid == to || A[mid+1] > target) {
                    return mid;
                }
                from = mid + 1;
            } else {
                to = mid - 1;
            }
        }
        return -1;
    }
    
    int find_lower(int A[], int from, int to, int target) {
        while (from <= to) {
            int mid = from + (to - from) / 2;
            
            if (A[mid] == target) {
                if (mid == from || A[mid-1] < target) {
                    return mid;
                }
                to = mid - 1;
            } else {
                from = mid + 1;
            }
        }
        return -1;
    }
    
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret = {-1, -1};
        if (n == 0 || target < A[0] || target > A[n-1]) {
            return ret;
        }
        
        int beg = 0, end = n - 1;
        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                beg = mid + 1;
            } else {  // find the target
                ret[0] = find_lower(A, beg, mid, target);
                ret[1] = find_upper(A, mid, end, target);
                break;
            }
        }
        
        return ret;
    }
};


// O(n): naive implementation
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret = {-1, -1};
        if (n == 0 || target < A[0] || target > A[n-1]) {
            return ret;
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] == target) {
                if (ret[0] == -1) {
                    ret[0] = i;
                }
            } else if (A[i] > target) {
                if (ret[1] == -1 && ret[0] != -1) {
                    ret[1] = i - 1;
                }
                break;
            }
        }
        if (ret[1] == -1 && ret[0] != -1) {
            ret[1] = n - 1;
        }
        
        return ret;
    }
};