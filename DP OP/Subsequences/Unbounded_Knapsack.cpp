//?https://www.codingninjas.com/codestudio/problem-details/unbounded-knapsack_1215029
//* Infinite supplies
//* Normal recurion - TC = Exponantial

#include <bits/stdc++.h>
using namespace std;

//! Memoization
//? TC = O(n*w), SC = O(n*w) + O(w);

// int f(int i, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
// {
//     if(i == 0) return (w/weight[0])*profit[0];
//     if(dp[i][w] != -1) return dp[i][w];
//     int notpick = f(i-1,w,profit,weight,dp);
//     int pick = 0;
//     if(w >= weight[i])
//          pick = profit[i] + f(i,w-weight[i],profit,weight,dp);
//     return dp[i][w] = max(pick, notpick);
// }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // vector<vector<int>> dp(n, vector<int> (w+1, -1));
    // return f(n-1,w,profit,weight,dp); //! #1

    //! Tabulation
    //? TC = O(n*w) , SC = O(n*w)

    // vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    // for (int wi = 0; wi <= w; wi++)
    //     dp[0][wi] = (wi / weight[0]) * profit[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int wi = 0; wi <= w; wi++)
    //     {
    //         int pick = 0;
    //         if (wi >= weight[i])
    //             pick = profit[i] + dp[i][wi - weight[i]];
    //         dp[i][wi] = max(dp[i - 1][wi], pick);
    //     }
    // }
    // return dp[n - 1][w];

    //! Space Optimization (2 vector)
    //? TC = O(n*w) , SC = O(2*w)

    // vector<int> dp(w + 1, 0), temp(w + 1, 0);
    // for (int wi = 0; wi <= w; wi++)
    //     dp[wi] = (wi / weight[0]) * profit[0];
    // for (int i = 1; i < n; i++)
    // {
    //     for (int wi = 0; wi <= w; wi++)
    //     {
    //         int pick = 0;
    //         if (wi >= weight[i])
    //             pick = profit[i] + temp[wi - weight[i]];
    //         temp[wi] = max(dp[wi], pick);
    //     }
    //     dp = temp;
    // }
    // return dp[w];

    //! Extereme Space Optimization (1 vector)
    //? TC = O(n*w) , SC = O(w)

    vector<int> dp(w + 1, 0);
    for (int wi = 0; wi <= w; wi++)
        dp[wi] = (wi / weight[0]) * profit[0];
    for (int i = 1; i < n; i++)
    {
        for (int wi = 0; wi <= w; wi++)
        {
            int pick = 0;
            if (wi >= weight[i])
                pick = profit[i] + dp[wi - weight[i]];
            dp[wi] = max(dp[wi], pick);
        }
    }
    return dp[w];

    //! Short version (EXTRAA)
    // vector<int> dp(w + 1, 0);
    // for (int wi = 0; wi <= w; wi++)
    //     dp[wi] = (wi / weight[0]) * profit[0];
    // for (int i = 1; i < n; i++)
    //     for (int wi = weight[i]; wi <= w; wi++)
    //         dp[wi] = max(dp[wi], profit[i] + dp[wi - weight[i]]);
    // return dp[w];
}
