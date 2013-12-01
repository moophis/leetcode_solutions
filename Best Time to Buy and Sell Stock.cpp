/**
 * Say you have an array for which the ith element is 
 * the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction 
 * (ie, buy one and sell one share of the stock), design an 
 * algorithm to find the maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        int min = INT_MAX;
        int maxp = INT_MIN;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                maxp = max(maxp, prices[i] - min);
            }
        }
        
        return maxp < 0 ? 0 : maxp;
    }
};