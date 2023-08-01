// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-iv
 *  RUNTIME: 46 ms
 *  MEMORY: 10.9 MB
 *  DATE: 12-23-2022, 6:42:07 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(k+1, 0), sell(k+1, 0);
        vector<int> prevBuy(k+1, 0), prevSell(k+1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int trans = 0; trans <= k; trans++)
            {
                buy[trans] = max(prevSell[trans] - prices[i], prevBuy[trans]);
                if (trans > 0)
                sell[trans] = max(prevSell[trans], prevBuy[trans - 1] + prices[i]);
                prevBuy = buy;
                prevSell = sell;
            }
        }
        return prevBuy[k];
    }
};
