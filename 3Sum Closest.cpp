// https://oj.leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if (size < 3) return 0;
        sort(num.begin(), num.end());
        
        int sum, diff = INT_MAX;
        int a(INT_MAX), b(INT_MAX), c(INT_MAX), last_a(INT_MAX), last_b(INT_MAX), last_c(INT_MAX);
        for (int i = 0; i < size - 2; i++) {
            a = num[i];
            
            int j = i + 1, k = size - 1;
            while (j < k) {
                b = num[j];
                c = num[k];
                
                int cur_sum = a + b + c;
                if (abs(cur_sum - target) < diff) {
                    sum = cur_sum;
                    diff = abs(cur_sum - target);
                } 
                
                if (cur_sum == target) {
                    return cur_sum;
                } else if (cur_sum > target) {
                    k--;
                } else {  // cur_sum < target
                    j++;
                }
            }
        }
        
        return sum;
    }
};