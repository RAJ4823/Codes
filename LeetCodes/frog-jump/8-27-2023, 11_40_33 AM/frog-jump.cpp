// Link: https://leetcode.com/problems/frog-jump

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: frog-jump
 *  RUNTIME: 156 ms
 *  MEMORY: 232.8 MB
 *  DATE: 8-27-2023, 11:40:33 AM
 *
 */

// Solution:

class Solution {
public:
    int n;
    bool find(int i, int k, vector<int> &stones, vector<vector<int>> &dp) {
        if(i == n-1) return true;
        if(dp[i][k] != -1) return dp[i][k];

        bool ans = false;
        for(int jump = max(k-1, 1); jump <= k+1; jump++){
            int next = lower_bound(stones.begin(),stones.end(), stones[i]+jump) - stones.begin();
            if(next < n && stones[next] == stones[i] + jump) {
                ans |= find(next, jump, stones, dp);
            }
        }
        return dp[i][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return find(0, 0, stones, dp);
    }
};
