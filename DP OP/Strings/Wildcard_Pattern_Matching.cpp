//? https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650

#include <bits/stdc++.h>
using namespace std;

//! Memoization (DP)
//? TC = O(n*m) , SC = O(n*m) + O(n+m)

bool f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0)
        return false;
    if (j < 0)
    {
        for (int ii = 0; ii <= i; ii++)
            if (s[ii] != '*')
                return false;
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
        
    bool ans = false;
    if (s[i] == '?' || s[i] == t[j])
        ans = f(i - 1, j - 1, s, t, dp);
    if (s[i] == '*')
        ans = (f(i - 1, j, s, t, dp) || f(i, j - 1, s, t, dp));
    return dp[i][j] = ans;
}

bool wildcardMatching(string &s, string &t)
{
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, t, dp); //! Memoization

    //! Tabulation (DP)
    //? TC = O(n*m) , SC = O(n*m)

    // vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    // for (int i = 1; i <= n; i++)
    // {
    //     bool flag = true;
    //     for (int ii = 1; ii <= i; ii++)
    //     {
    //         if (s[ii - 1] != '*')
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     dp[i][0] = flag;
    // }
    // dp[0][0] = true;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (s[i - 1] == '?' || s[i - 1] == t[j - 1])
    //             dp[i][j] = dp[i - 1][j - 1];
    //         else if (s[i - 1] == '*')
    //             dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
    //         else
    //             dp[i][j] = false;
    //     }
    // }
    // return dp[n][m];

    //! Space Optimized
    //? TC = O(n*m), SC = O(2*m)

    // vector<bool> dp(m + 1, false), temp(m + 1, false);
    // dp[0] = true;
    // for (int i = 1; i <= n; i++)
    // {
    //     // For every row you have to assign its 0th collumn value using base case
    //     bool flag = true;
    //     for (int ii = 1; ii <= i; ii++)
    //     {
    //         if (s[ii - 1] != '*')
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     temp[0] = flag;

    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (s[i - 1] == '?' || s[i - 1] == t[j - 1])
    //             temp[j] = dp[j - 1];
    //         else if (s[i - 1] == '*')
    //             temp[j] = (dp[j] || temp[j - 1]);
    //         else
    //             temp[j] = false;
    //     }
    //     dp = temp;
    // }
    // return dp[m];
}
