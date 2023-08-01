// Link: https://leetcode.com/problems/stone-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game
 *  RUNTIME: 24 ms
 *  MEMORY: 16.4 MB
 *  DATE: 5-27-2023, 11:30:00 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(i == j) return arr[i];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int left = arr[i] - find(i+1, j, arr, dp);
        int right= arr[j] - find(i, j-1, arr, dp);
        
        return dp[i][j] = max(left, right);
    }
    bool stoneGame(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // int res = find(0, n-1, arr, dp);
        for(int i=n-1; i>=0; i--) {
            for(int j=0; j<n; j++) {
                if(i > j) continue;
                
                int left = arr[i], right = arr[j];
                if(i+1 < n) left -= dp[i+1][j];
                if(j-1>= 0) right-= dp[i][j-1];
                dp[i][j] = max(left, right);
            }
        }
        return (dp[0][n-1] > 0);
    }
};
