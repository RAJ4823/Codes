//?https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091
//* Normal recursion - TC > O(2^n) (exponential) & SC > O(x)

#include <bits/stdc++.h>
using namespace std;

//! Memoization (recursive DP)
//? TC = O(n*x), SC = O(n*x) + O(x)

// int f(int i, int x, vector<int> &num, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         if (x % num[0] == 0)
//             return x / num[0];
//         return 1e9;
//     }
//     if (dp[i][x] != -1)
//         return dp[i][x];
//     int notpick = f(i - 1, x, num, dp);
//     int pick = INT_MAX;
//     if (x >= num[i])
//         pick = 1 + f(i, x - num[i], num, dp);
//     return dp[i][x] = min(pick, notpick);
// }

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    // int ans = f(n - 1, x, num, dp); //! #1

    //! Tabulation (iterative DP) #2
    //? TC = O(n*x), SC = O(n*x)

    // vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    // for (int sum = 0; sum <= x; sum++)
    // {
    //     if (sum % num[0] == 0)
    //         dp[0][sum] = (sum / num[0]);
    //     else
    //         dp[0][sum] = 1e9;
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int sum = 0; sum <= x; sum++)
    //     {
    //         int pick = INT_MAX;
    //         int notpick = dp[i - 1][sum];
    //         if (sum >= num[i])
    //             pick = 1 + dp[i][sum - num[i]];
    //         dp[i][sum] = min(notpick, pick);
    //     }
    // }
    // int ans = dp[n - 1][x];

    //! Space Optimization #3
    //? TC = O(n*x), SC = O(2*x)

    // vector<int> dp(x + 1, 0), temp(x + 1, 0);
    // for (int sum = 0; sum <= x; sum++)
    // {
    //     if (sum % num[0] == 0)
    //         dp[sum] = (sum / num[0]);
    //     else
    //         dp[sum] = 1e9;
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int sum = 0; sum <= x; sum++)
    //     {
    //         int pick = INT_MAX;
    //         int notpick = dp[sum];
    //         if (sum >= num[i])
    //             pick = 1 + temp[sum - num[i]];
    //         temp[sum] = min(notpick, pick);
    //     }
    //     dp = temp;
    // }
    // int ans = dp[x];

    //! EXTREME Space Optimization #4
    //? TC = O(n*x), SC = O(x)

    vector<int> dp(x + 1, 0);
    for (int sum = 0; sum <= x; sum++)
    {
        if (sum % num[0] == 0)
            dp[sum] = (sum / num[0]);
        else
            dp[sum] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int sum = x; sum >= num[i]; sum--)
        {
            dp[sum] = min(dp[sum], 1 + dp[sum - num[i]]);
        }
    }
    int ans = dp[x];

    //!-1 checker code (fixed for all)
    if (ans >= 1e9)
        return -1;
    return ans;
}