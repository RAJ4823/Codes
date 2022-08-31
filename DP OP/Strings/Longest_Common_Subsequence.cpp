//? https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_1063255
//* Two index in one recursion method to optimize TC

#include <bits/stdc++.h>
using namespace std;

//! Memoization
//? TC = O(n*m) , SC = O(n*m) + O(n+m)

// int lcs(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
// {
//     if (i < 0 || j < 0)     return 0;
//     if (dp[i][j] != -1)     return dp[i][j];
//     int match = 0, notmatch = 0;
//     if (str1[i] == str2[j])
//         match = 1 + lcs(i - 1, j - 1, str1, str2, dp);
//     else
//         notmatch = max(lcs(i - 1, j, str1, str2, dp), lcs(i, j - 1, str1, str2, dp));
//     return dp[i][j] = max(match, notmatch);
// }

int getLengthOfLCS(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();

    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // return lcs(n - 1, m - 1, str1, str2, dp); //! #1

    //! Tabulation
    //? TC = O(n*m) SC = O(n*m)

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         int match = 0, notmatch = 0;
    //         if (str1[i - 1] == str2[j - 1])
    //             match = 1 + dp[i - 1][j - 1];
    //         else
    //             notmatch = max(dp[i - 1][j], dp[i][j - 1]);
    //         dp[i][j] = max(match, notmatch);
    //     }
    // }
    // return dp[n][m];

    //! Space Optimization
    //? TC = O(n*m) SC = O(m)

    vector<int> dp(m + 1, 0), temp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int match = 0, notmatch = 0;
            if (str1[i - 1] == str2[j - 1])
                match = 1 + dp[j - 1];
            else
                notmatch = max(dp[j], temp[j - 1]);
            temp[j] = max(match, notmatch);
        }
        dp = temp;
    }
    return dp[m];
}