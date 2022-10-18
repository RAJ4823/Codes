//* Using Longest_Common_Subsequence solution
//* Backtracking DP Matrix of that soln

#include <bits/stdc++.h>
using namespace std;

void traceback(string str1, string str2, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return;
    if (str1[i - 1] == str2[j - 1])
    {
        traceback(str1, str2, i - 1, j - 1, dp);
        cout << str1[i - 1];
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
        traceback(str1, str2, i - 1, j, dp);
    }
    else
    {
        traceback(str1, str2, i, j - 1, dp);
    }
}

string print_lcs(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    //! Recursive Approach
    // traceback(str1, str2, n, m, dp);

    //! BACKTRACKING (Iterative approach)
    int len = dp[n][m];
    int i = n, j = m;
    int index = len - 1;

    //Filling temp values
    string str3 = "";
    for (int k = 0; k < len; k++)
        str3 += '$';

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            //Because of : dp[i][j] = 1 + dp[i - 1][j - 1]
            str3[index] = str1[i - 1];
            index--;
            i--;
            j--;
        }
        // Because of : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return str3;
}

int main()
{
    string str1, str2;
    str1 = "racecar";
    str2 = "acecard";
    cout << print_lcs(str1, str2);
}