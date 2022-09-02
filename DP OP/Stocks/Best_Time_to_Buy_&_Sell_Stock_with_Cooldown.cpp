//? https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969
//! You can not buy stoock after selling, you have to wait for one day
//* just little modification of 'i+2' in sell of PART 2

#include <bits/stdc++.h>
using namespace std;
#define v1 vector<int>
#define v2 vector<v1>
#define v3 vector<v2>

//! Memoization (DP)
//? TC = O(n*2) , SC = O(n*2) + O(n);
int f(int i, int buy, v1 &values, int n, v2 &dp)
{
    if (i >= n) // modification
        return 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    int profit = 0;
    if (buy)
    {
        int buy_it = f(i + 1, 0, values, n, dp) - values[i];
        int not_buy_it = f(i + 1, 1, values, n, dp);
        profit = max(buy_it, not_buy_it);
    }
    else
    {
        int sell_it = f(i + 2, 1, values, n, dp) + values[i]; // modification
        int not_sell_it = f(i + 1, 0, values, n, dp);
        profit = max(sell_it, not_sell_it);
    }
    return dp[i][buy] = profit;
}

int stockProfit(vector<int> &prices)
{
    int n = prices.size();
    v2 dp(n, v1(2, -1));
    return f(0, 1, prices, n, dp);
}
