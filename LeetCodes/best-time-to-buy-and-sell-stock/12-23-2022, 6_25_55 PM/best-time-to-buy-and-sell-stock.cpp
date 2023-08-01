// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock
 *  RUNTIME: 385 ms
 *  MEMORY: 93.4 MB
 *  DATE: 12-23-2022, 6:25:55 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0], profit = 0;
        for(int i=0; i<n; i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
