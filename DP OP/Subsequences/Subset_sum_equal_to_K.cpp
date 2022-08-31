//?https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h>
using namespace std;

//! Recursion (TLE)
//? TC = O(2^n) , SC = O(n)

// bool f(int n, int target, vector<int> &arr)
// {
//     if (target < 0 || n < 0) return false;
//     if (target == 0) return true;
//     bool not_pick = f(n - 1, target, arr);
//     bool pick = f(n - 1, target - arr[n], arr);
//     return (not_pick || pick);
// }

//! Memoization (recurive DP)
//? TC = O(n*k) , SC = O(n) + O(n*k)

// bool f(int n,int target, vector<int> &arr, vector<vector<int>> &dp) {
//     if(target == 0)         return true;
//     if(n == 0)              return (target == arr[0]);
//     if(dp[n][target] != -1) return dp[n][target];
//     bool not_pick = f(n-1,target, arr, dp);
//     bool pick = false;
//     if(target >= arr[n])
//         pick = f(n-1, target-arr[n], arr, dp);
//     return dp[n][target] = (not_pick || pick);
// }

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // return f(n - 1, k, arr); //!1

    // vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // return f(n - 1, k, arr, dp); //!2

    //! Tabulation (iterative DP)
    //? TC = O(n*k) , SC = O(n*k)

    // vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // for (int i = 0; i < n; i++)
    //     dp[i][0] = true;
    // dp[0][arr[0]] = true;
    // for (int i = 1; i < n; i++)
    // {
    //     for (int target = 0; target <= k; target++)
    //     {
    //         bool np = false, p = false;
    //         np = dp[i - 1][target];
    //         if (target - arr[i] >= 0)
    //             p = dp[i - 1][target - arr[i]];
    //         dp[i][target] = (p || np);
    //     }
    // }
    // return dp[n - 1][k];

    //! Space optimization
    //? TC = O(n*k) , SC = O(k)

    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            bool np = false, p = false;
            np = prev[target];
            if (target - arr[i] >= 0)
                p = prev[target - arr[i]];
            curr[target] = (p || np);
        }
        prev = curr;
    }
    return prev[k];
}