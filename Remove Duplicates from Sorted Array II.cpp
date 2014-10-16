// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

// Better solution
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        int pre = 1, cur = 1;
        int occur = 1;
        
        while (cur < n) {
            if (A[cur-1] == A[cur]) {
                if (occur == 1) {
                    occur++;
                } else if (occur >= 2) {
                    cur++;
                    continue;
                }
            } else {
                occur = 1;
            }
            
            A[pre++] = A[cur++];
        }
        
        return pre;
    }
};

// Just acceptable solution
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        unordered_map<int, int> occurence;
        int removed = 0;
        
        for (int i = 0; i < n - removed; i++) {
            if (occurence.count(A[i]) == 0) {
                occurence.emplace(A[i], 1);
            } else if (occurence[A[i]] == 2) {
                removed++;
                for (int j = i; j < n - 1; j++) {
                    swap(A[j], A[j+1]);
                }
                i--;  // swapped new value, avoid moving forward
            } else {  // only found once before
                occurence[A[i]]++;
            }
        }
        
        return n - removed;
    }
};