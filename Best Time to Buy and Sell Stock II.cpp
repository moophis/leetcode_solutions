class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int profits = 0;
    
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i-1] < prices[i]) {
                profits += prices[i] - prices[i-1];
            } 
        }
        
        return profits;
    }
};