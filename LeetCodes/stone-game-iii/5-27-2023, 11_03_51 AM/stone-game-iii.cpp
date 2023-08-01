// Link: https://leetcode.com/problems/stone-game-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-iii
 *  RUNTIME: 239 ms
 *  MEMORY: 132.2 MB
 *  DATE: 5-27-2023, 11:03:51 AM
 *
 */

// Solution:

class Solution {
public:
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            int maxi = INT_MIN, sum = 0;
            for(int k=i; k<min(i+3, n); k++) {
                sum += arr[k];
                maxi = max(maxi, sum - dp[k+1]);
            }
            dp[i] = maxi;
        }
        int res = dp[0];
        if(res > 0) return "Alice";
        else if(res < 0) return "Bob";
        return "Tie"; 
    }
};
