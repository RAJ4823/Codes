// Link: https://leetcode.com/problems/solving-questions-with-brainpower

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: solving-questions-with-brainpower
 *  RUNTIME: 387 ms
 *  MEMORY: 115.2 MB
 *  DATE: 5-12-2023, 10:58:49 AM
 *
 */

// Solution:

#define ll long long 

class Solution {
public:
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<ll> dp(n, 0);

        for(int i=n-1; i>=0; i--) {
            ll take = arr[i][0], nottake = 0;
            if(i + 1 + arr[i][1] < n)
                take += dp[i + 1 + arr[i][1]];
            if(i + 1 < n)
                nottake += dp[i+1];
            dp[i] = max(take, nottake);
        }
        return dp[0];
    }
};
