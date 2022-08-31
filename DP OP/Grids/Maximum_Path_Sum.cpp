//?https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
//* Variable starting and ending point

#include <bits/stdc++.h>
using namespace std;

//! Using memoisation (recursive- DP)
//? TC = O(n*m), SC = O(n*m) + O(n)
//* Might get TLE because of recursive function call time

// int f(int i, int j, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
// {
//     if (j < 0 || j >= m)
//         return -1e9;
//     if (i == 0)
//         return mat[0][j];
//     if (dp[i][j] != -1e9)
//         return dp[i][j];
//     int up = mat[i][j] + f(i - 1, j, m, mat, dp);
//     int lu = mat[i][j] + f(i - 1, j - 1, m, mat, dp);
//     int ru = mat[i][j] + f(i - 1, j + 1, m, mat, dp);
//     return dp[i][j] = max(up, max(lu, ru));
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    //! 1
    // vector<vector<int>> dp(n, vector<int>(m, -1e9));
    // int max_sum = -1e9;
    // for (int j = 0; j < m; j++)
    // {
    //     max_sum = max(max_sum, f(n - 1, j, m, matrix, dp));
    // }
    // return max_sum;

    //! Using tabulation (iterative- DP) //2
    //? TC - O(n*m), SC - (n*m)

    // vector<vector<int>> dp(n, vector<int>(m, -1e9));
    // int max_sum = -1e9;
    // for (int j = 0; j < m; j++)
    // {
    //     dp[0][j] = matrix[0][j];
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         int up = -1e9, lu = -1e9, ru = -1e9;
    //         up = matrix[i][j] + dp[i - 1][j];
    //         if (j > 0)
    //             lu = matrix[i][j] + dp[i - 1][j - 1];
    //         if (j < m - 1)
    //             ru = matrix[i][j] + dp[i - 1][j + 1];
    //         dp[i][j] = max(up, max(ru, lu));
    //     }
    // }
    // for (int j = 0; j < m; j++)
    // {
    //     max_sum = max(max_sum, dp[n - 1][j]);
    // }
    // return max_sum;

    //! Space optimization //3
    //? TC - O(n*m), SC - (m)

    vector<int> dp(m, -1e9);
    int max_sum = -1e9;
    for (int j = 0; j < m; j++)
    {
        dp[j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(m, -1e9);
        for (int j = 0; j < m; j++)
        {
            int up = -1e9, lu = -1e9, ru = -1e9;
            up = matrix[i][j] + dp[j];
            if (j > 0)
                lu = matrix[i][j] + dp[j - 1];
            if (j < m - 1)
                ru = matrix[i][j] + dp[j + 1];
            temp[j] = max(up, max(ru, lu));
        }
        dp = temp;
    }
    for (int j = 0; j < m; j++)
    {
        max_sum = max(max_sum, dp[j]);
    }
    return max_sum;
}