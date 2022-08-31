//?https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
#include <bits/stdc++.h>
using namespace std;

//! Recursion method (TLE)
//? TC = O(2^n),  SC = O(n+m)

// int f(int i, int j, vector<vector<int>> &grid)
// {
//     if (i == 0 && j == 0) return grid[0][0];
//     if (i < 0 || j < 0)   return 1e9;
//     //return MAX_POSSIBLE_NUMBER insted of INT_MAX
//     int up = grid[i][j] + f(i - 1, j, grid);
//     int left = grid[i][j] + f(i, j - 1, grid);
//     return min(up, left);
// }

//! Using memoisation (recursive- DP)
//? TC = O(n*m), SC = O(n*m) + O(n+m)

int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)   return grid[0][0];
    if (i < 0 || j < 0)     return 1e9;
    if (dp[i][j] != -1)     return dp[i][j];
    // return MAX_POSSIBLE_NUMBER insted of INT_MAX
    int up = grid[i][j] + f(i - 1, j, grid, dp);
    int left = grid[i][j] + f(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // return f(n - 1, m - 1, grid); //!1

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp); //!2

    //! Using tabulation (iterative- DP) //3
    //? TC - O(n*m), SC - (n*m)

    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0 && j == 0)
    //             dp[0][0] = grid[0][0];
    //         else
    //         {
    //             int up = 1e9, left = 1e9;
    //             if (i > 0)   up = dp[i - 1][j];
    //             if (j > 0) left = dp[i][j - 1];
    //             dp[i][j] = grid[i][j] + min(up, left);
    //         }
    //     }
    // }
    // return dp[n - 1][m - 1];

    //! Space Optimization //4
    //?  TC - O(n*m), SC - O(n)

    // vector<int> prev(m, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> temp(m, 0);
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0 && j == 0)
    //             temp[0] = grid[0][0];
    //         else
    //         {
    //             int up = 1e9, left = 1e9;
    //             if (i > 0)    up = prev[j];
    //             if (j > 0)  left = temp[j-1];
    //             temp[j] = grid[i][j] + min(up, left);
    //         }
    //     }
    //     prev = temp;
    // }
    // return prev[m - 1];
}