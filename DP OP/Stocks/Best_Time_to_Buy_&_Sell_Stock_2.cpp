//? https://www.codingninjas.com/codestudio/problems/selling-stock_630282
//! You can buy & sell stocks as many time as you want
//* You can not but multiple stocks without selling previous

#include <bits/stdc++.h>
using namespace std;

//! Memoization (DP)
//? TC = O(n*2) , SC = O(n*2) + O(n);

// long f(int i, int buy, long *values, int n, vector<vector<long>> &dp)
// {
//     if (i == n)
//         return 0;
//     if (dp[i][buy] != -1)
//         return dp[i][buy];
//     long profit = 0;
//     if (buy)
//     {
//         long buy_it = f(i + 1, 0, values, n, dp) - values[i];
//         long not_buy_it = f(i + 1, 1, values, n, dp);
//         profit = max(buy_it, not_buy_it);
//     }
//     else
//     {
//         long sell_it = f(i + 1, 1, values, n, dp) + values[i];
//         long not_sell_it = f(i + 1, 0, values, n, dp);
//         profit = max(sell_it, not_sell_it);
//     }
//     return dp[i][buy] = profit;
// }

long getMaximumProfit(long *values, int n)
{
    // vector<vector<long>> dp(n, vector<long>(2, -1));
    // return f(0, 1, values, n, dp); //! Memoization

    //! Tabulation (DP)
    //? TC = O(n*2) , SC = O(n*2)

    // vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    // dp[n][0] = dp[n][1] = 0;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int buy = 0; buy <= 1; buy++)
    //     {
    //         long profit = 0;
    //         if (buy)
    //             profit = max(dp[i + 1][0] - values[i], dp[i + 1][1]);
    //         else
    //             profit = max(dp[i + 1][1] + values[i], dp[i + 1][0]);
    //         dp[i][buy] = profit;
    //     }
    // }
    // return dp[0][1];

    //! Tabulation (SMALL CODE)
    //? TC = O(n), SC = O(n*2)
    // vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    // dp[n][0] = dp[n][1] = 0;

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     dp[i][1] = max(dp[i + 1][0] - values[i], dp[i + 1][1]);
    //     dp[i][0] = max(dp[i + 1][1] + values[i], dp[i + 1][0]);
    // }
    // return dp[0][1];

    //! Space Optimization
    //? TC = O(n) , SC = O(1)

    long buy = 0, sell = 0;
    long prevBuy = 0, prevSell = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        buy = max(prevSell - values[i], buy);
        sell = max(prevBuy + values[i], sell);
        prevBuy = buy;
        prevSell = sell;
    }
    return prevBuy;
}