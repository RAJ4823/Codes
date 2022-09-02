//? https://www.codingninjas.com/codestudio/problems/selling-stock_630282
//! You can buy & sell stocks only 2 times
//* 3D DP & Modifies the code of PART 2

#include <bits/stdc++.h>
using namespace std;
#define v1 vector<int>
#define v2 vector<v1>
#define v3 vector<v2>

//* Approch 1 : By using buy/sell and trans as different
//! Memoization (DP)
//? TC = O(n*6) , SC = O(n*6) + O(n);
// int f(int i, int buy, int trans, v1 &values, int n, v3 &dp)
// {
//     if (trans == 0)
//         return 0;
//     if (i == n)
//         return 0;
//     if (dp[i][buy][trans] != -1)
//         return dp[i][buy][trans];
//     int profit = 0;
//     if (buy)
//     {
//         int buy_it = f(i + 1, 0, trans, values, n, dp) - values[i];
//         int not_buy_it = f(i + 1, 1, trans, values, n, dp);
//         profit = max(buy_it, not_buy_it);
//     }
//     else
//     {
//         long sell_it = f(i + 1, 1, trans - 1, values, n, dp) + values[i];
//         long not_sell_it = f(i + 1, 0, trans, values, n, dp);
//         profit = max(sell_it, not_sell_it);
//     }
//     return dp[i][buy][trans] = profit;
// }

int maxProfit(vector<int> &prices, int n)
{
    // v3 dp(n, v2(2, v1(3, -1)));
    // //  f(index, buy/notBuy, transactions, prices vector, size of price, dp)
    // return f(0, 1, 2, prices, n, dp); //! Memoization

    //! Tabulation
    //? TC = O(n*6) , SC = O(n*6);
    // v3 dp(n + 1, v2(2, v1(3, 0)));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int buy = 0; buy <= 1; buy++)
    //     {
    //         for (int trans = 0; trans <= 2; trans++)
    //         {
    //             long profit = 0;
    //             if (buy)
    //                 profit = max(dp[i + 1][0][trans] - prices[i], dp[i + 1][1][trans]);
    //             else
    //             {
    //                 int sell_it = 0;
    //                 if (trans > 0)
    //                     sell_it = dp[i + 1][1][trans - 1] + prices[i];
    //                 profit = max(sell_it, dp[i + 1][0][trans]);
    //             }
    //             dp[i][buy][trans] = profit;
    //         }
    //     }
    // }
    // return dp[0][1][2];

    //! Small Code of Tabulation
    //? TC = O(n*3)

    // v3 dp(n + 1, v2(2, v1(3, 0)));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int trans = 0; trans <= 2; trans++)
    //     {
    //         dp[i][1][trans] = max(dp[i + 1][0][trans] - prices[i], dp[i + 1][1][trans]);
    //         int temp = dp[i + 1][0][trans];
    //         if (trans > 0)
    //             dp[i][0][trans] = max(temp, dp[i + 1][1][trans - 1] + prices[i]);
    //     }
    // }
    // return dp[0][1][2];

    //! Space Optimized
    //? TC = O(n*3) , SC = O(4*3) = O(12)

    v1 buy(3, 0), sell(3, 0);
    v1 prevBuy(3, 0), prevSell(3, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int trans = 0; trans <= 2; trans++)
        {
            buy[trans] = max(prevSell[trans] - prices[i], prevBuy[trans]);
            int temp = prevSell[trans];
            if (trans > 0)
                sell[trans] = max(temp, prevBuy[trans - 1] + prices[i]);
            prevBuy = buy;
            prevSell = sell;
        }
    }
    return prevBuy[2];
}

//* Approch 2 : By using trans number for buy/sell
//* if trans is even means buy and odd means sell
//* here trans number = 2*given trans number because : 1 buy + 1 sell = 1 trans
//! Memoization (DP)
//? TC = O(n*4) , SC = O(n*4) + O(n)
// int f(int i, int trans, int n, int k, v1 &prices, v2 &dp)
// {
//     if (i == n || trans == k)
//         return 0;
//     if (dp[i][trans] != -1)
//         return dp[i][trans];
//     int profit = 0;
//     if (trans % 2 == 0) // Buy
//     {
//         int buy = f(i + 1, trans + 1, n, k, prices, dp) - prices[i];
//         int notBuy = f(i + 1, trans, n, k, prices, dp);
//         profit = max(buy, notBuy);
//     }
//     else // sell
//     {
//         int sell = f(i + 1, trans + 1, n, k, prices, dp) + prices[i];
//         int notSell = f(i + 1, trans, n, k, prices, dp);
//         profit = max(sell, notSell);
//     }
//     return dp[i][trans] = profit;
// }

int maxProfit(vector<int> &prices, int n)
{
    int k = 2; //! transaction count
    // v2 dp(n, v1(2 * k, -1));
    // return f(0, 0, n, 2 * k, prices, dp); //! Memoization

    //! Tabulation (DP)
    //? TC = O(n*4), SC = O(n*4)

    // v2 dp(n + 1, v1(2 * k + 1, 0));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int trans = 0; trans < 2 * k; trans++)
    //     {
    //         int profit = 0;
    //         if (trans % 2 == 0) // Buy
    //         {
    //             int buy = dp[i + 1][trans + 1] - prices[i];
    //             int notBuy = dp[i + 1][trans];
    //             profit = max(buy, notBuy);
    //         }
    //         else // sell
    //         {
    //             int sell = dp[i + 1][trans + 1] + prices[i];
    //             int notSell = dp[i + 1][trans];
    //             profit = max(sell, notSell);
    //         }
    //         dp[i][trans] = profit;
    //     }
    // }
    // return dp[0][0];
    //! Very Small Code of Tabulation
    // v2 dp(n + 1, v1(2 * k + 1, 0));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int trans = 0; trans < 2*k; trans++)
    //     {
    //         // 1 = '+' (sell), -1 = '-'(Buy)
    //         int sign = -1;
    //         if (trans % 2)  sign = 1;
    //         dp[i][trans] = max(dp[i + 1][trans + 1] + sign * prices[i], dp[i + 1][trans]);
    //     }
    // }
    // return dp[0][0];

    //! Space Optimization (DP)
    //? TC = O(n*4), SC = O(8)
    v1 dp(2 * k + 1, 0), temp(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int trans = 0; trans < 2 * k; trans++)
        {
            // 1 = '+' (sell), -1 = '-'(Buy)
            int sign = -1;
            if (trans % 2)
                sign = 1;
            temp[trans] = max(dp[trans + 1] + sign * prices[i], dp[trans]);
        }
        dp = temp;
    }
    return dp[0];
}