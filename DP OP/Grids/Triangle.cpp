//?https://www.codingninjas.com/codestudio/problems/triangle_1229398
//* Fixed starting point and Variable ending point

#include <bits/stdc++.h>
using namespace std;

//! recursive DP (memoization)
//? TC ~ O(n2), SC = O(n) + O(n2)

int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
        return a[i][j];
    if(dp[i][j] != -1)
        return dp[i][j];
    int bottom = a[i][j] + f(i + 1, j, a, dp, n);
    int diagonal = a[i][j] + f(i + 1, j + 1, a, dp, n);
    return dp[i][j] = min(bottom, diagonal);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, 0, triangle, dp, n); //!1.

    //! iterative DP (tabulation) 2
    //? TC ~ O(n2) , SC = o(n2)

    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // for (int j = 0; j < n; j++)
    // {
    //     // settting base case value of recursion
    //     dp[n - 1][j] = triangle[n - 1][j];
    // }
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     for (int j = i; j >= 0; j--)
    //     {
    //         dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    //         //* OR
    //         // int bottom = triangle[i][j] + dp[i + 1][j];
    //         // int diagonal = triangle[i][j] + dp[i + 1][j + 1];
    //         // dp[i][j] = min(bottom, diagonal);
    //     }
    // }
    // return dp[0][0];

    //! Space Optimization 3
    //? TC ~ O(n2) , SC = o(n)

    // vector<int> prev(n, 0);
    // for (int j = 0; j < n; j++)
    // {
    //     prev[j] = triangle[n - 1][j];
    // }
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     vector<int> curr(n, 0);
    //     for (int j = i; j >= 0; j--)
    //     {
    //         curr[j] = triangle[i][j] + min(prev[j], prev[j + 1]);
    //     }
    //     prev = curr;
    // }
    // return prev[0];
}