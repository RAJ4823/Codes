// Link: https://leetcode.com/problems/edit-distance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: edit-distance
 *  RUNTIME: 3 ms
 *  MEMORY: 6.5 MB
 *  DATE: 2-26-2023, 10:00:20 AM
 *
 */

// Solution:

class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        vector<int> dp(M + 1, 0), temp(M + 1, 0);
        for (int j = 0; j <= M; j++) dp[j] = j;
        for (int i = 1; i <= N; i++)
        {
            temp[0] = i;
            for (int j = 1; j <= M; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + min(temp[j - 1], min(dp[j], dp[j - 1]));
            }
            dp = temp;
        }
        return dp[M];
    }
};
