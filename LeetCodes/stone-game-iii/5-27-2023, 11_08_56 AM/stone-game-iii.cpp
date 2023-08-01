// Link: https://leetcode.com/problems/stone-game-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-iii
 *  RUNTIME: 230 ms
 *  MEMORY: 126.4 MB
 *  DATE: 5-27-2023, 11:08:56 AM
 *
 */

// Solution:

class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(3, 0);
        string ans[3] = {"Bob", "Tie", "Alice"};

        for(int i=n-1; i>=0; i--) {
            int maxi = INT_MIN, sum = 0;
            for(int k=i; k<min(i+3, n); k++) {
                sum += arr[k];
                maxi = max(maxi, sum - dp[(k+1) % 3]);
            }
            dp[i % 3] = maxi;
        }
        int res = (dp[0]) ? dp[0] / abs(dp[0]) : 0 ;
        return ans[res + 1];
    }
};
