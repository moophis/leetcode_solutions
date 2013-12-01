/**
 * Say you have an array for which the ith element
 * is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. 
 * You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time 
 * (ie, you must sell the stock before you buy again).
 */
 
/*
 * Use dynamic programming:
 * We should notice that the two transactions should be interleaving,
 * so we can do this job in two passes:
 *
 * 1. For the first pass, we scan prices from 0 to n-1, while iteratively
 * finding the maximum profits at each step and updating the lowest 
 * prices. (because to get maximum profits we should buy it at lowest price)
 *
 * 2. For the second pass, we scan prices from n-1 to 0 to get the 
 * second transaction's information. For each step j, we should compare the
 * maximum profits of 0 to j and j to n-1.
 * 
 * The second pass does the dynamic programming thing, the first pass takes
 * charge of building the table for one transaction.
 */
 
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        vector<int> max_sofar;  // max profits from 0 to i
        int minp = prices[0];   // lowest point
        int max_profits = 0;
        
        // first scan from 0 to i to find the possible first transaction
        max_sofar.push_back(0);
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - minp > max_profits) {
                max_profits = prices[i] - minp;
            }
            max_sofar.push_back(max_profits);
            if (prices[i] < minp) {  // update lowest point
                minp = prices[i];
            }
        }
        
        int ret = max_sofar[prices.size() - 1]; // max profits from 0 to i
        int max_p = prices[prices.size() - 1];  // highest points
        int max_combined = 0;                   // combined max profits
        max_profits = 0;
        
        // second scan from i to 0 to find the second possible transaction
        // while comparing for the combined transactions which contribute to
        // maximum profits.
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (max_p - prices[i] > max_profits) {
                max_profits = max_p - prices[i];
            }
            max_combined = max_profits + max_sofar[i];
            ret = max(max_combined, ret);
            if (prices[i] > max_p) {  // update highest point
                max_p = prices[i];
            }
        }
        
        return ret;
    }
};