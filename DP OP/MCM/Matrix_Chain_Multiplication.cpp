//! https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344
#include <bits/stdc++.h>
using namespace std;

//! Memoization (recurive DP)
//? TC = O(n^3), SC = O(n^2) + O(n)
// int MCM(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (i == j)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     int totalSteps = 0, minSteps = 1e9;
//     for (int k = i; k < j; k++)
//     {
//         totalSteps = (arr[i - 1] * arr[k] * arr[j]) + MCM(i, k, arr, dp) + MCM(k + 1, j, arr, dp);
//         minSteps = min(minSteps, totalSteps);
//     }
//     return dp[i][j] = minSteps;
// }

int matrixMultiplication(vector<int> &arr, int n)
{
    //? vector is easy to pass in functions compared to 2D array :) 
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return MCM(1, n - 1, arr, dp); //! 1

    //! Tabulation (iterative DP)
    //? TC = O(n^3), SC = O(n^2)
    int dp[n][n];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int totalSteps = 0, minSteps = 1e9;
            for (int k = i; k < j; k++)
            {
                totalSteps = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                minSteps = min(minSteps, totalSteps);
            }
            dp[i][j] = minSteps;
        }
    }
    return dp[1][n - 1];
}