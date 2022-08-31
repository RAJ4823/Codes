//?https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
//* Minimum Deletions from string A = (length of string A - lcs(string A, string B))
//* Minimum Insertions into String B = (length of string B - lsc(string A, string B))
//* Final Answer = Sum of both results ^^

#include <bits/stdc++.h>
using namespace std;

//* LCS = Longest Common Subsequence
int lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
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

int canYouMake(string &str, string &ptr)
{
    int common = lcs(str, ptr);
    int deletions = str.length() - common;
    int insertions = ptr.length() - common;
    return (insertions + deletions);
}