//?https://www.codingninjas.com/codestudio/problems/subsequence-counting_3755256

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

//! Memoization (DP)
//? TC = O(n*m) , SC = O(n+m) + O(n*m)
// int f(int i, int j, string &t, string &s, vector<vector<int>> &dp)
// {
//     if (j < 0)  return 1;
//     if (i < 0)  return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (t[i] == s[j])
//         return dp[i][j] = (f(i - 1, j - 1, t, s, dp) % mod + f(i - 1, j, t, s, dp) % mod) % mod;
//     return dp[i][j] = f(i - 1, j, t, s, dp) % mod;
// }

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    // Write your code here.
    // vector<vector<int>> dp(lt, vector<int>(ls, -1));
    // return f(lt - 1, ls - 1, t, s, dp);

    //! Tabulation (DP)
    //? TC = O(n*m) , SC = O(n*m)
    // vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));
    // for (int i = 0; i <= lt; i++)
    //     dp[i][0] = 1;
    // for (int i = 1; i <= lt; i++)
    // {
    //     for (int j = 1; j <= ls; j++)
    //     {
    //         if (t[i - 1] == s[j - 1])
    //             dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
    //         else
    //             dp[i][j] = (dp[i - 1][j]) % mod;
    //     }
    // }
    // return dp[ls][lt];

    //! Space Optimized
    //? TC = O(n*m) , SC = O(2*m)
    vector<int> dp(ls + 1, 0), temp(ls + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= lt; i++)
    {
        temp[0] = 1;
        for (int j = 1; j <= ls; j++)
        {
            if (t[i - 1] == s[j - 1])
                temp[j] = (dp[j - 1] % mod + dp[j] % mod) % mod;
            else
                temp[j] = (dp[j]) % mod;
        }
        dp = temp;
    }
    return dp[ls];
}