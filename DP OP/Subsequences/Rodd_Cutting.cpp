
#include <bits/stdc++.h>
using namespace std;

//! Memoization
//?  TC = O(n*n) , SC = O(n*n) + O(n)

// int f(int i, int N, vector<int> &price, vector<vector<int>> &dp)
// {
//     if (i == 0) return N * price[0];
//     if (dp[i][N] != -1) return dp[i][N];
//     int notpick = f(i - 1, N, price, dp);
//     int pick = INT_MIN;
//     if (N >= (i + 1))
//         pick = price[i] + f(i, N - (i + 1), price, dp);
//     return dp[i][N] = max(pick, notpick);
// }

int cutRod(vector<int> &price, int n)
{
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return f(n - 1, n, price, dp); //! #1

    //! Tabulation
    //? TC = O(n*n) , SC = O(n*n)

    // vector<vector<int>> dp(n, vector<int>(n + 1, INT_MIN));
    // for (int i = 0; i <= n; i++)
    //     dp[0][i] = i * price[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         int pick = INT_MIN;
    //         if (j >= (i + 1))
    //             pick = price[i] + dp[i][j - (i + 1)];
    //         dp[i][j] = max(dp[i - 1][j], pick);
    //     }
    // }
    // return dp[n - 1][n];

    //! Space Optimization
    //? TC = O(n*n) , SC = O(2*n)

    // vector<int> dp(n + 1, INT_MIN), temp(n + 1, INT_MIN);
    // for (int i = 0; i <= n; i++)
    //     dp[i] = i * price[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         int pick = INT_MIN;
    //         if (j >= (i + 1))
    //             pick = price[i] + temp[j - (i + 1)];
    //         temp[j] = max(dp[j], pick);
    //     }
    //     dp = temp;
    // }
    // return dp[n];

    //! Extreme Space Optimization
    //? TC = O(n*n) , SC = O(n)

    vector<int> dp(n + 1, INT_MIN);
    for (int i = 0; i <= n; i++)
        dp[i] = i * price[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int pick = INT_MIN;
            if (j >= (i + 1))
                pick = price[i] + dp[j - (i + 1)];
            dp[j] = max(dp[j], pick);
        }
    }
    return dp[n];

    //! Short Version (extraa)
    // vector<int> dp(n + 1, INT_MIN);
    // for (int i = 0; i <= n; i++)
    //     dp[i] = i * price[0];
    // for (int i = 1; i < n; i++)
    //     for (int j = (i + 1); j <= n; j++)
    //         dp[j] = max(dp[j], price[i] + dp[j - (i + 1)]);
    // return dp[n];
}