// Link: https://leetcode.com/problems/buy-two-chocolates

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: buy-two-chocolates
 *  RUNTIME: 16 ms
 *  MEMORY: 46.9 MB
 *  DATE: 12-20-2023, 11:30:02 AM
 *
 */

// Solution:

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(auto &val: prices) {
            if(val <= min1) {
                min2 = min1;
                min1 = val;
            } else if(val < min2) {
                min2 = val;
            }
        }
        int sum = min1 + min2;
        if(sum <= money) 
            return money - sum;
        return money;
    }
};
