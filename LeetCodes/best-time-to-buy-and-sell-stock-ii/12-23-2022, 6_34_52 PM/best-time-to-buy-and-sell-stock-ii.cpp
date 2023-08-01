// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-time-to-buy-and-sell-stock-ii
 *  RUNTIME: 7 ms
 *  MEMORY: 13.1 MB
 *  DATE: 12-23-2022, 6:34:52 PM
 *
 */

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
        int buy = 0, sell = 0;
        int prevBuy = 0, prevSell = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            buy = max(prevSell - values[i], buy);
            sell = max(prevBuy + values[i], sell);
            prevBuy = buy;
            prevSell = sell;
        }
        return prevBuy;
    }
};
