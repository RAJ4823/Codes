// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock
 *  RUNTIME: 123 ms
 *  MEMORY: 93.4 MB
 *  DATE: 2-25-2023, 2:18:21 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;
        for(int i=0; i<prices.size(); i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
