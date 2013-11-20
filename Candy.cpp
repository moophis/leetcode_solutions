/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * 
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */

/* 
 * Use two way scan:
 * 1) First scan: detect ascending ratings and increases candies accordingly;
 *                (adjust the order of the left neighbour)
 * 2) Second scan: reversely detect ascending ratings and increases candies accordingly;
 *                (adjust the order of the right neighbour)
 * This way we can handle the case of tie ratings (keep them as small as possible)
 */ 

class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (ratings.size() == 0)
            return 0;
            
        int n = static_cast<int> (ratings.size());
        int sum = 0;
        vector<int> assigned(n, 0);
        
        // forward scan
        for (int i = 0; i < n - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                assigned[i + 1] = assigned[i] + 1;
            } 
        }
        
        // backward scan
        for (int i = n - 1; i > 0; i--) {
            if (ratings[i] < ratings[i - 1]) {
                assigned[i - 1] = max(assigned[i] + 1, assigned[i - 1]);
            } 
        }
        
        for (int i = 0; i < n; i++) {
            sum += assigned[i];
        }
        
        return sum + n;
    }
};