// Link: https://leetcode.com/problems/stone-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game
 *  RUNTIME: 47 ms
 *  MEMORY: 16.3 MB
 *  DATE: 5-27-2023, 11:20:11 AM
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
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        int res = find(0, n-1, arr, dp);
        return (res > 0);
    }
};
