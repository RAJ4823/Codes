// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-insertion-steps-to-make-a-string-palindrome
 *  RUNTIME: 68 ms
 *  MEMORY: 6.7 MB
 *  DATE: 4-22-2023, 9:25:20 AM
 *
 */

// Solution:

class Solution {
public:
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

    int minInsertions(string s) {
        string str1 = s; // Given string
        reverse(s.begin(), s.end());
        string str2 = s; // Reverse string

        return s.length() - lcs(str1, str2);
    }
};
