// Link: https://leetcode.com/problems/stone-game-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-iii
 *  RUNTIME: 268 ms
 *  MEMORY: 137.6 MB
 *  DATE: 5-27-2023, 11:00:31 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> dp;
    int n;
    int find(int i, vector<int> &arr) {
        if(i >= n)    return 0;
        if(dp[i] != INT_MAX)   return dp[i];

        int maxi = INT_MIN, sum = 0;
        for(int k=i; k<min(i+3, n); k++) {
            sum += arr[k];
            maxi = max(maxi, sum - find(k+1, arr));
        }
        return dp[i] = maxi;
    }   
    string stoneGameIII(vector<int>& arr) {
        n = arr.size();
        dp.resize(n, INT_MAX);
        int res = find(0, arr);
        if(res > 0) return "Alice";
        else if(res < 0) return "Bob";
        return "Tie"; 
    }
};
