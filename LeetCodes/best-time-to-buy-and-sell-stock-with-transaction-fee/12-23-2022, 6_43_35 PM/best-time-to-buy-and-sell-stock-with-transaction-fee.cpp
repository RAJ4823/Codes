// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-with-transaction-fee
 *  RUNTIME: 295 ms
 *  MEMORY: 55 MB
 *  DATE: 12-23-2022, 6:43:35 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& values, int fee) {
        int n = values.size();
        int buy = 0, sell = 0;
        int prevBuy = 0, prevSell = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            buy = max(prevSell - values[i], buy);
            sell = max(prevBuy + values[i] - fee, sell);
            prevBuy = buy;
            prevSell = sell;
        }
        return prevBuy;
    }
};
