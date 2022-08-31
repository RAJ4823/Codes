//?https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
//* Fixed starting and ending point

#include <bits/stdc++.h>
using namespace std;

//! Recursion method (TLE)
//? TC = O(2^n),  SC = O(n+m)

// int f(int i,int j) {
//     if(i==0 && j==0) return 1;
//     if(i< 0 || j< 0) return 0;
//     return  f(i-1,j) + f(i,j-1);
// }

//! Using memoisation (recursive- DP)
//? TC = O(n*m), SC = O(n*m) + O(n+m)

// int f(int i, int j, vector<vector<int>> &dp)
// {
//     if (i == 0 && j == 0)   return 1;
//     if (i < 0 || j < 0)     return 0;
//     if (dp[i][j] != -1)     return dp[i][j];
//     return dp[i][j] = (f(i - 1, j, dp) + f(i, j - 1, dp));
// }

int uniquePaths(int m, int n)
{
    // return f(m-1,n-1); //!1
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return f(m - 1, n - 1, dp); //!2

    //! Using tabulation (iterative- DP) //3
    //? TC - O(n*m), SC - (n*m)

    // vector<vector<int>> dp(m, vector<int>(n, 0));
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         int up = 0, left = 0;
    //         if (i == 0 && j == 0)
    //             dp[i][j] = 1;
    //         else
    //         {
    //             if (i > 0)
    //                 up = dp[i - 1][j];
    //             if (j > 0)
    //                 left = dp[i][j - 1];
    //             dp[i][j] = (up + left);
    //         }
    //     }
    // }
    // return dp[m - 1][n - 1];

    //! Space Optimization //4
    //?  TC - O(n*m), SC - O(n)

    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            int up = 0, left = 0;
            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                up = prev[j];
                left = temp[j-1];
                temp[j] = (up + left);
            }
        }
        prev = temp;
    }
    return prev[n-1];
}