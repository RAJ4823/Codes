//? https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
//* Recursion solution is not possible

#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2)
{
    int n = str1.size();
    int m = str2.size();
    int maxi = 0;

    //! Tabulation
    //? TC = O(n*m) , SC = O(n*m)

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         int match = 0, notmatch = 0;
    //         if (str1[i - 1] == str2[j - 1])
    //             dp[i][j] = 1 + dp[i - 1][j - 1];
    //         else
    //             dp[i][j] = 0;
    //         maxi = max(maxi, dp[i][j]);
    //     }
    // }
    // return maxi;

    //! Space Optimization
    //? TC = O(n*m) , SC = O(m)

    vector<int> dp(m + 1, 0), temp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int match = 0, notmatch = 0;
            if (str1[i - 1] == str2[j - 1])
                temp[j] = 1 + dp[j - 1];
            else
                temp[j] = 0;
            maxi = max(maxi, temp[j]);
        }
        dp = temp;
    }
    return maxi;
}
