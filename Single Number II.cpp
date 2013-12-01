/**
 * Given an array of integers, every element appears three 
 * times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity.
 * Could you implement it without using extra memory?
 */

// canonical bit-manipulating problem
class Solution {
public:
    int singleNumber(int A[], int n) {
        int count = 0;
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 0x01) {
                    count++;
                }
            }
            result |= (count % 3) << i;
            count = 0;
        }
        
        return result;
    }
};