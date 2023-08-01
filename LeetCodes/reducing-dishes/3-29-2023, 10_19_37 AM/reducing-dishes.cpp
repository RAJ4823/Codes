// Link: https://leetcode.com/problems/reducing-dishes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reducing-dishes
 *  RUNTIME: 20 ms
 *  MEMORY: 20.8 MB
 *  DATE: 3-29-2023, 10:19:37 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0;
    int sumAll(int inx, int mul, vector<int> &arr, vector<vector<int>> &dp) {
        int sum = 0;
        for(int i=inx; i<n; ++i) {
            // dp[i][mul] = sum;
            sum += (arr[i] * mul);
            mul++;
        }
        return sum;
    }

    int find(int inx, int mul, vector<int> &arr, vector<vector<int>> &dp) {
        if(inx >= n) return 0;
        if(dp[inx][mul] != -1) return dp[inx][mul];

        if(arr[inx] >= 0) {
            return dp[inx][mul] = sumAll(inx, mul, arr, dp);
        }

        int take = arr[inx] * mul + find(inx + 1, mul + 1, arr, dp);
        int nottake = find(inx + 1, mul, arr, dp);
        return dp[inx][mul] = max(take, nottake);
    }

    int maxSatisfaction(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return find(0, 1, arr, dp);
    }
};
