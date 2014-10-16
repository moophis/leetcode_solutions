// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// simpler solution
class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if (size == 0) {
            return 0;
        }
        
        int start = 0, end = size - 1;
        if (num[start] <= num[end]) {
            return num[start];
        }
        while (end - start > 1) {
            int mid = start + (end - start) / 2;
            if (num[start] < num[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        return num[end];
    }
};

// By finding the large skew
class Solution {
public:
    int findMin(vector<int> &num) {
        int size = num.size();
        if (size == 0) {
            return 0;
        }
        
        int start = 0, end = size - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (num[(mid - 1 + size) % size] >= num[mid]) {
                return num[mid];
            } 
            if (num[start] > num[end]) {
                if (num[mid] >= num[start]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                end = mid - 1;
            }
        }
        
        return -1;  // it should not happen
    }
};