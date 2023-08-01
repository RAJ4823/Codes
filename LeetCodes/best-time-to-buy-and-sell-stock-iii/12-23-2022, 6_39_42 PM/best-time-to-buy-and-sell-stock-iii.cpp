// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-iii
 *  RUNTIME: 363 ms
 *  MEMORY: 75.4 MB
 *  DATE: 12-23-2022, 6:39:42 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(3, 0), sell(3, 0);
        vector<int> prevBuy(3, 0), prevSell(3, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int trans = 0; trans <= 2; trans++)
            {
                buy[trans] = max(prevSell[trans] - prices[i], prevBuy[trans]);
                if (trans > 0)
                sell[trans] = max(prevSell[trans], prevBuy[trans - 1] + prices[i]);
                prevBuy = buy;
                prevSell = sell;
            }
        }
        return prevBuy[2];
    }
};
