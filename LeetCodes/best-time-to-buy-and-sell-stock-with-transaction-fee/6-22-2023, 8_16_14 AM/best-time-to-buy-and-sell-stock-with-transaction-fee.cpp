// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-with-transaction-fee
 *  RUNTIME: 290 ms
 *  MEMORY: 95.6 MB
 *  DATE: 6-22-2023, 8:16:14 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> dp;
    int find(int i, int fee, int buy, vector<int> &values) {
        if(i == values.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit;
        if(buy) {
            int skip = find(i+1, fee, 1, values);
            int buyit = find(i+1, fee, 0, values) - values[i]; 
            profit = max(skip, buyit);
        } else {
            int skip = find(i+1, fee, 0, values);
            int sellit = find(i+1, fee, 1, values) + values[i] - fee;
            profit = max(skip, sellit);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& values, int fee) {
        int n = values.size();
        dp.resize(n, vector<int> (2, -1));
        return find(0, fee, 1, values);
    }
};
