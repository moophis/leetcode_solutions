// https://oj.leetcode.com/problems/next-permutation/
// Refer to: http://nayuki.eigenstate.org/page/next-lexicographical-permutation-algorithm

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Find the largest index i such that num[i-1] < num[i]
        int pivot = -1;
        for (int i = num.size() - 1; i >= 1; i--) {
            if (num[i-1] < num[i]) {
                pivot = i - 1;
                break;
            }
        }
        
        if (pivot != -1) {
            // Find the largest index j such that j >= i and num[j] > num[i-1]
            // Then swap num[j] and num[i-1]
            for (int j = num.size() - 1; j > pivot; j--) {
                if (num[j] > num[pivot]) {
                    swap(num[j], num[pivot]);
                    break;
                }
            }
        }
        
        // Reverse the suffix starting at num[i]
        int head = pivot + 1;
        int tail = num.size() - 1;
        while (head < tail) {
            swap(num[head++], num[tail--]);
        }
    }
};