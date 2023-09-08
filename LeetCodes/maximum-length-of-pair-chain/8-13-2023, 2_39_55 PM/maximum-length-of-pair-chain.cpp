// Link: https://leetcode.com/problems/maximum-length-of-pair-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-length-of-pair-chain
 *  RUNTIME: 466 ms
 *  MEMORY: 159.3 MB
 *  DATE: 8-13-2023, 2:39:55 PM
 *
 */

// Solution:

class Solution {
public:
    int find(int curr, int prev, vector<vector<int>>& pairs, vector<vector<int>>& dp) {
        if(curr == 0) return pairs[curr][1] < pairs[prev][0];
        if(dp[curr][prev] != -1) return dp[curr][prev];

        int take = 0, nottake = 0;
        if(pairs[curr][1] < pairs[prev][0]) {
            take = 1 + find(curr - 1, curr, pairs, dp);
        }
        nottake = find(curr - 1, prev, pairs, dp);
        return dp[curr][prev] = max(take, nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();

        pairs.push_back({INT_MAX, INT_MAX});
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return find(n-1, n, pairs, dp);
    }
};
