// Link: https://leetcode.com/problems/coin-change-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: coin-change-ii
 *  RUNTIME: 23 ms
 *  MEMORY: 19 MB
 *  DATE: 8-11-2023, 10:24:14 AM
 *
 */

// Solution:

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
        vector<int> curr(amount+1, 0), prev(amount+1, 0);

        curr[0] = prev[0] = 1;
        for(int i=1; i<=n; i++) {
            curr[0] = prev[0] = 1;
            for(int sum=1; sum <= amount; sum++) {
                if(sum >= coins[i-1]) {
                    curr[sum] = curr[sum - coins[i-1]] + prev[sum];
                } else {
                    curr[sum] = prev[sum];
                }
            }
            prev = curr;
        }
        return curr[amount];
    }
};
