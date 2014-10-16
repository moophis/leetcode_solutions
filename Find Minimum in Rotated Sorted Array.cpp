// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

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