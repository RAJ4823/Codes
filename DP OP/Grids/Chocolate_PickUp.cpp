//?https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0
//* Fixes starting points (2 starting) and varible ending point
//* Simultaneously move two point
//* 3D DP Vector
//! Normal recursion TC = 9^n (TLE)

#include <bits/stdc++.h>
using namespace std;

//! Recursive DP (Memoization)
//? TC - O(n*m*m*9) , SC = O(n*m*m) + O(n)

int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if ((j1 < 0 || j1 >= m) || (j2 < 0 || j2 >= m))
        return -1e9;
    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1e9)
        return dp[i][j1][j2];

    int maxi = 0, curr = 0;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            if (j1 == j2)
                curr = grid[i][j1] + f(i + 1, j1 + d1, j2 + d2, n, m, grid, dp);
            else
                curr = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + d1, j2 + d2, n, m, grid, dp);
            maxi = max(maxi, curr);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    //               <3D vector> = dp(size,  <2D vector> (size,<1D vector> (size, value)))
    // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1e9)));
    // return f(0, 0, m - 1, n, m, grid, dp);

    //! Tabulation (iterative DP)
    //? TC = O(n*m*m*9), SC = O(n*m*m)

    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e9)));
    // for (int j1 = 0; j1 < m; j1++)
    // {
    //     for (int j2 = 0; j2 < m; j2++)
    //     {
    //         if (j1 == j2)
    //             dp[n - 1][j1][j2] = grid[n - 1][j1];
    //         else
    //             dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    //     }
    // }
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     for (int j1 = 0; j1 < m; j1++)
    //     {
    //         for (int j2 = 0; j2 < m; j2++)
    //         {
    //             int maxi = 0, curr = -1e9;
    //             for (int d1 = -1; d1 <= 1; d1++)
    //             {
    //                 for (int d2 = -1; d2 <= 1; d2++)
    //                 {
    //                     if ((j1 + d1 >= 0 && j1 + d1 < m) && (j2 + d2 >= 0 && j2 + d2 < m))
    //                     {
    //                         if (j1 == j2)
    //                             curr = grid[i][j1] + dp[i + 1][j1 + d1][j2 + d2];
    //                         else
    //                             curr = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + d1][j2 + d2];
    //                     }
    //                     maxi = max(maxi, curr);
    //                 }
    //             }
    //             dp[i][j1][j2] = maxi;
    //         }
    //     }
    // }
    // return dp[0][0][m - 1];

    //! Space Optimization
    //? TC = O(n*m*m*9), SC = O(m*m)

    vector<vector<int>> dp(m, vector<int>(m, -1e9));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[j1][j2] = grid[n - 1][j1];
            else
                dp[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(m, vector<int>(m, -1e9));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = 0, curr = -1e9;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        if ((j1 + d1 >= 0 && j1 + d1 < m) && (j2 + d2 >= 0 && j2 + d2 < m))
                        {
                            if (j1 == j2)
                                curr = grid[i][j1] + dp[j1 + d1][j2 + d2];
                            else
                                curr = grid[i][j1] + grid[i][j2] + dp[j1 + d1][j2 + d2];
                        }
                        maxi = max(maxi, curr);
                    }
                }
                temp[j1][j2] = maxi;
            }
        }
        dp = temp;
    }
    return dp[0][m - 1];
}