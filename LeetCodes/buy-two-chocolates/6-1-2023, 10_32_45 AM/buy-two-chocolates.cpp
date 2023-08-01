// Link: https://leetcode.com/problems/buy-two-chocolates

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: buy-two-chocolates
 *  RUNTIME: 41 ms
 *  MEMORY: 46.6 MB
 *  DATE: 6-1-2023, 10:32:45 AM
 *
 */

// Solution:

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int sum = prices[0] + prices[1];
        if(sum <= money) return money - sum;
        return money;
    }
};
