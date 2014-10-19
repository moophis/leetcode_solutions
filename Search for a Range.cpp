// https://oj.leetcode.com/problems/search-for-a-range/

// even cleaner solution
class Solution {
    int search_left(int A[], int n, int target) {
        int s = 0, e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (A[m] == target) {
                if (m == s || A[m-1] != target) {
                    return m;
                } else {
                    e = m - 1;
                }
            } else if (A[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }
    
    int search_right(int A[], int n, int target) {
        int s = 0, e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (A[m] == target) {
                if (m == e || A[m+1] != target) {
                    return m;
                } else {
                    s = m + 1;
                }
            } else if (A[m] > target) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }
    
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n <= 0) {
            return {-1, -1};
        }
        vector<int> ret(2);
        ret[0] = search_left(A, n, target);
        ret[1] = search_right(A, n, target);
        return ret;
    }
};


// cleaner solution
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret = {-1, -1};
        if (n == 0 || target < A[0] || target > A[n-1]) {
            return ret;
        }
        
        int beg = 0, end = n - 1;
        
        // find lower bound
        while (beg < end) {
            int mid = beg + (end - beg) / 2;  // try to move backward
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        ret[0] = end;
        if (A[ret[0]] != target) {
            return {-1, -1};
        }
        
        // find upper bound
        beg = 0;
        end = n - 1;
        while (beg < end) {
            int mid = beg + (end - beg + 1) / 2;  // try to move forward
            if (A[mid] > target) {
                end = mid - 1;
            } else if (A[mid] < target) {
                beg = mid + 1;
            } else {
                beg = mid;
            }
        }
        ret[1] = beg;
        if (A[ret[1]] != target) {
            return {-1, -1};
        }
        
        return ret;
    }
};


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