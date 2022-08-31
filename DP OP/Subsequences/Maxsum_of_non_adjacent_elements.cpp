//?https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <bits/stdc++.h>
using namespace std;

//! Memoization (recursive DP)
//? TC = O(n) , SC = O(n) + O(n)

// int f(int n, vector<int> &nums, vector<int> &dp) {
//     if(n == 0) return nums[0];
//     if(n <  0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int pick = nums[n] + f(n-2, nums, dp);
//     int notp = f(n-1 , nums, dp);
//     return dp[n] = max(pick, notp);
// }

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // vector<int> dp(n, -1);
    // return f(n-1, nums, dp); //!1

    //! Tabulation (iterative DP)
    //? TC = O(n), SC = O(n)

    // vector<int> dp(n, 0);
    // dp[0] = nums[0];
    // for (int i = 1; i < n; i++)
    // {
    //     int pick = 0, notp = 0;
    //     notp = dp[i - 1];
    //     if (n >= 2)
    //         pick = nums[i] + dp[i - 2];
    //     dp[i] = max(pick, notp);
    // }
    // return dp[n-1];

    //! Space Optimization
    //? TC = O(n), SC = O(1)

    int prev1, prev2 = 0, curr = 0;
    prev1 = nums[0];
    for (int i = 1; i < n; i++)
    {
        int pick = 0, notp = 0;
        notp = prev1;
        if (n >= 2)
            pick = nums[i] + prev2;
        curr = max(pick, notp);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}