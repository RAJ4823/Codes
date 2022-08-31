//? https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
//* Length of SCS  = length of (string A + string B) - LCS(string A, string B)

//* Using Longest_Common_Subsequence solution
//* Backtracking DP Matrix of that soln

#include <bits/stdc++.h>
using namespace std;

//* From Print LCS
string shortestSupersequence(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    //* Filling dp table by findig LCS
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

    //! BACKTRACKING

    int len = (n + m) - dp[n][m];
    int i = n, j = m;
    int index = len - 1;

    // Filling temp values
    string str3 = "";
    for (int k = 0; k < len; k++)
        str3 += '$';

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            // Because of : dp[i][j] = 1 + dp[i - 1][j - 1]
            str3[index--] = str1[i - 1];
            i--;
            j--;
        }
        // Because of : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            str3[index--] = str1[i - 1];
            i--;
        }
        else
        {
            str3[index--] = str2[j - 1];
            j--;
        }
    }

    while (i--)
        str3[index--] = str1[i];
    while (j--)
        str3[index--] = str2[j];

    //? Or you can '+=' to str3 and reverse at the end
    return str3;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        cout << shortestSupersequence(str1, str2) << endl;
    }
    return 0;
}