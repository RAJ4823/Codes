#include <bits/stdc++.h>
using namespace std;
#define ll long long

//! Pass by reference otherwise will give TLE
int fun(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (i < 0) // insert all remaining characters of str2
        return (j + 1);
    if (j < 0) // delete all remaining characters of str1
        return (i + 1);
    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = fun(i - 1, j - 1, str1, str2, dp);

    int del = 1 + fun(i - 1, j, str1, str2, dp);     // deletion
    int rep = 1 + fun(i - 1, j - 1, str1, str2, dp); // replace
    int ins = 1 + fun(i, j - 1, str1, str2, dp);     // insertion

    return dp[i][j] = min(del, min(rep, ins));
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << fun(n - 1, m - 1, str1, str2, dp) << endl;

    //! Tabulation
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // for (int i = 0; i <= n; i++)
    //     dp[i][0] = i;
    // for (int j = 0; j <= m; j++)
    //     dp[0][j] = j;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (str1[i - 1] == str2[j - 1])
    //             dp[i][j] = dp[i - 1][j - 1];
    //         else
    //         {
    //             int del = 1 + dp[i - 1][j];     // deletion
    //             int rep = 1 + dp[i - 1][j - 1]; // replace
    //             int ins = 1 + dp[i][j - 1];     // insertion
    //             dp[i][j] = min(rep, min(del, ins));
    //         }
    //     }
    // }
    // cout << dp[n][m] << endl;
    return 0;
}