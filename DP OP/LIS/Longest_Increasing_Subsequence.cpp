//? https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459

#include <bits/stdc++.h>
using namespace std;

//! Memoization
//? TC = O(n*n) , SC = O(n*n) + O(n)
//* Will give RUN TIME ERROR for n <= 10^5
//* Because 10^5 x 10^5 size vector is not possible

int f(int i, int prev, int n, int arr[], vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];
    int notpick = f(i + 1, prev, n, arr, dp);
    int pick = 0;
    if (prev == -1 || arr[i] > arr[prev])
        pick = 1 + f(i + 1, i, n, arr, dp);
    return dp[i][prev + 1] = max(pick, notpick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return f(0, -1, n, arr, dp);

    //! Tabulation
    //? TC = O(n*n) , SC = O(n*n)
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int prev = i - 1; prev >= -1; prev--)
    //     {
    //         int pick = 0;
    //         if (prev == -1 || arr[i] > arr[prev])
    //             pick = 1 + dp[i + 1][i + 1];
    //         dp[i][prev + 1] = max(pick, dp[i + 1][prev + 1]);
    //     }
    // }
    // return dp[0][0];

    //! Space optimized
    //? TC = O(n*n) , SC = O(n)
    vector<int> dp(n + 1, 0), temp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int pick = 0;
            if (prev == -1 || arr[i] > arr[prev])
                pick = 1 + dp[i + 1];
            temp[prev + 1] = max(pick, dp[prev + 1]);
        }
        dp = temp;
    }
    return dp[0];

    //! Another algorithm (0 to n approch)
    //? TC = O(n*n) , SC = O(n)
    vector<int> dp(n, 1);
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i])
                dp[i] = max(1 + dp[prev], dp[i]);
        }
        len = max(len, dp[i]);
    }
    return len;
}