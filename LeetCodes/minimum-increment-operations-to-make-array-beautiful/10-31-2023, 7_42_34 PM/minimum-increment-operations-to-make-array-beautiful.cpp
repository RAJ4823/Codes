// Link: https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-increment-operations-to-make-array-beautiful
 *  RUNTIME: 114 ms
 *  MEMORY: 86.5 MB
 *  DATE: 10-31-2023, 7:42:34 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> dp(n+5, 0);
        for(int i=n-1; i>=0; i--) {
            ll prev = min({dp[i+1], dp[i+2], dp[i+3]});
            dp[i] = prev + max(0, k - nums[i]); 
        }
        ll ans = min({dp[0], dp[1], dp[2]});
        return ans;
    }
};
