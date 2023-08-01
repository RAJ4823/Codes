// Link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-value-of-k-coins-from-piles
 *  RUNTIME: 292 ms
 *  MEMORY: 18.3 MB
 *  DATE: 4-15-2023, 10:04:54 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int find(int cur, int rem, vector<vector<int>> &piles) {
        if(cur >= n) return 0;
        if(dp[cur][rem] != 0) return dp[cur][rem];

        int nottake = find(cur+1, rem, piles);
        int sum = 0, take = 0;
        for(int i=0; i < piles[cur].size(); i++) {
            sum += piles[cur][i];
            int newRem = rem - (i+1);
            if(newRem >= 0) {
                take = max(take, sum + find(cur + 1,newRem, piles));
            }
        }
        return dp[cur][rem] = max(take, nottake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.resize(n+1, vector<int> (k+1, 0));
        return find(0, k, piles);
    }
};

// class Solution {
//     public:
//         int dp[2001][2001] = { 0 };
//     int maxValueOfCoins(vector < vector < int >> & piles, int k) {
//         return solve(0, piles, k);
//     }
//     int solve(int index, vector < vector < int >> & piles, int k) {
//         if (index >= piles.size()) return 0;
//         if (dp[index][k] != 0) return dp[index][k];
//         int maxi = 0, sum = 0;
//         //either dont take from that pile
//         maxi = max(maxi, solve(index + 1, piles, k));
//         for (int i = 0; i < piles[index].size(); i++) {
//             sum += piles[index][i];
//             //or take some certain prefix from that pile, if we can take that much elements.
//             if (k - (i + 1) >= 0) maxi = max(maxi, sum + solve(index + 1, piles, k - (i + 1)));
//         }
//         return dp[index][k] = maxi;
//     }
// };
