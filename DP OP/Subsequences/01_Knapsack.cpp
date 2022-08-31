//? https://www.codingninjas.com/codestudio/problem-details/0-1-knapsack_920542
//* Single supply

#include <bits/stdc++.h>
using namespace std;

//! Memoization (recurive DP)
//? TC = O(n*w), SC = O(n*w) + O(n)

// int f(int i, int w, vector<int> weight, vector<int> value, vector<vector<int>> &dp)
// {
//     if (i == 0)
//     {
//         if (w >= weight[0])
//             return value[0];
//         return 0;
//     }
//     if (dp[i][w] != -1)
//         return dp[i][w];
//     int notpick = f(i - 1, w, weight, value, dp);
//     int pick = 0;
//     if (w >= weight[i])
//         pick = value[i] + f(i - 1, w - weight[i], weight, value, dp);
//     return dp[i][w] = max(pick, notpick);
// }

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
    // return f(n-1, maxWeight, weight, value, dp); //! #1

    //! Tabulation (iteraetive DP) #2
    //? TC = O(n*w), SC = O(n*w)

    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // for (int i = weight[0]; i <= maxWeight; i++)
    //     dp[0][i] = value[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int w = 0; w <= maxWeight; w++)
    //     {
    //         int pick = 0;
    //         if (w >= weight[i])
    //             pick = value[i] + dp[i - 1][w - weight[i]];
    //         dp[i][w] = max(dp[i - 1][w], pick);
    //     }
    // }
    // return dp[n - 1][maxWeight];

    //! Space Optimization (2 vectors) #3
    //? TC = O(n*w), SC = O(w) (originally O(2*w))

    // vector<int> dp(maxWeight + 1, 0), temp(maxWeight + 1, 0);
    // for (int i = weight[0]; i <= maxWeight; i++)
    //     dp[i] = value[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int w = 0; w <= maxWeight; w++)
    //     {
    //         int pick = 0;
    //         if (w >= weight[i])
    //             pick = value[i] + dp[w - weight[i]];
    //         temp[w] = max(dp[w], pick);
    //     }
    //     dp = temp;
    // }
    // return dp[maxWeight];

    //! Extreme Space Optimization (1 vectors) #4
    //? TC = O(n*w), SC = O(w)

    vector<int> dp(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
        dp[i] = value[0];
    for (int i = 1; i < n; i++)
    {
        // Moving right to left for filling values that only tequires left sides
        for (int w = maxWeight; w >= 0; w--)
        {
            int pick = 0;
            if (w >= weight[i])
                pick = value[i] + dp[w - weight[i]];
            dp[w] = max(dp[w], pick);
        }
    }
    return dp[maxWeight];

    //! Short Version (Extraa)
    // vector<int> dp(maxWeight + 1, 0);
    // for (int i = weight[0]; i <= maxWeight; i++)
    //     dp[i] = value[0];
    // for (int i = 1; i < n; i++)
    //     for (int w = maxWeight; w >= weight[i]; w--)
    //         dp[w] = max(dp[w], value[i] + dp[w - weight[i]]);
    // return dp[maxWeight];
}