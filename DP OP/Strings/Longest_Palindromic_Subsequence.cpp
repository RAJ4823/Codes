//?https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787
//* Longest Palindrome Subsequence is a Longest common subsequence of given string and its reverse string
//* LPS(str) = LCS(str, reverse(str));

#include <bits/stdc++.h>
using namespace std;

//! LCS (Space Optimized method)
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

int longestPalindromeSubsequence(string s)
{
    string str1 = s; // Given string
    reverse(s.begin(), s.end());
    string str2 = s; // Reverse string

    return lcs(str1, str2);
}