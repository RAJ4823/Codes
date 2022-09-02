//? https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
//* It memoizing the minimum value of the given array till index i using iteration so it is comes under DP
//! You can only buy and sell once

#include <bits/stdc++.h>
using namespace std;

//! Space Optimized 
//? TC = O(n), SC = O(1)
int maximumProfit(vector<int> &prices)
{

    int mini = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        profit = max(profit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    return profit;
}