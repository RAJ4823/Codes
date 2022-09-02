//? https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974
//! Have to pay fee after each successful transcation
//* just little modification of '-fee' in sell of PART 2

#include <bits/stdc++.h>
using namespace std;
#define v1 vector<int>
#define v2 vector<v1>
#define v3 vector<v2>

//! Memoization (DP)
//? TC = O(n*2) , SC = O(n*2) + O(n);
// int f(int i, int buy, v1 &prices, int n, int fee, v2 &dp)
// {
//     if (i == n) // modification
//         return 0;
//     if (dp[i][buy] != -1)
//         return dp[i][buy];
//     int profit = 0;
//     if (buy)
//     {
//         int buy_it = f(i + 1, 0, prices, n, fee, dp) - prices[i];
//         int not_buy_it = f(i + 1, 1, prices, n, fee, dp);
//         profit = max(buy_it, not_buy_it);
//     }
//     else
//     {
//         int sell_it = f(i + 1, 1, prices, n, fee, dp) + prices[i] - fee; // modification
//         int not_sell_it = f(i + 1, 0, prices, n, fee, dp);
//         profit = max(sell_it, not_sell_it);
//     }
//     return dp[i][buy] = profit;
// }

int maximumProfit(int n, int fee, vector<int> &prices)
{
    // v2 dp(n, v1(2, -1));
    // return f(0, 1, prices, n, fee, dp); //! Memoization

    //! Space Optimization
    //? TC = O(n) , SC = O(1)

    long buy = 0, sell = 0;
    long prevBuy = 0, prevSell = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        buy = max(prevSell - prices[i], buy);
        sell = max(prevBuy + prices[i] - fee, sell);
        prevBuy = buy;
        prevSell = sell;
    }
    return prevBuy;
}
