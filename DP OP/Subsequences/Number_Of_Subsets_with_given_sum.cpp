//?https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

#include <bits/stdc++.h>
using namespace std;

//! Memoization (recursive DP)
//? TC = O(n*sum) , SC = O(n*sum) + O(n);

// int f(int ind, int sum,  vector<int> &num, vector<vector<int>> &dp)
// {
//     if(ind == 0)
//     {
//         if(sum == 0 && num[0] == 0) return 2;
//         if(sum == 0 || sum == num[0]) return 1;
//         return 0;
//     }
//     if(dp[ind][sum] != -1) return dp[ind][sum];
//     int notpick = f(ind-1,sum,num,dp);
//     int pick = 0;
//     if(sum >= num[ind])
//         pick = f(ind-1, sum - num[ind], num, dp);
//     return dp[ind][sum] = (pick + notpick);
// }

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    // vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    // return f(n - 1, tar, num, dp); //! #1

    //! Tabulation (iterative DP) #2
    //? TC = O(n*sum) , SC = O(n*sum);
    // vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = 1;
    // if (num[0] <= tar)
    //     dp[0][num[0]] = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int sum = 0; sum <= tar; sum++)
    //     {
    //         int x = 0;
    //         if (sum >= num[i])
    //             x = dp[i - 1][sum - num[i]];
    //         dp[i][sum] = (dp[i - 1][sum] + x);
    //     }
    // }
    // return dp[n - 1][tar];

    //! Space Optimization #3
    //? TC = O(n^2) , SC = O(sum);

    vector<int> dp(tar + 1, 0), temp(tar + 1, 0);
    dp[0] = 1;
    if (num[0] <= tar)
        dp[num[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int x = 0;
            if (sum >= num[i])
                x = dp[sum - num[i]];
            temp[sum] = (dp[sum] + x);
        }
        dp = temp;
    }
    return dp[tar];
}