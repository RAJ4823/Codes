// Link: https://leetcode.com/problems/longest-common-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-common-subsequence
 *  RUNTIME: 39 ms
 *  MEMORY: 13.3 MB
 *  DATE: 12-15-2022, 3:11:20 PM
 *
 */

// Solution:

class Solution {
private: 
    int lcs(int i, int j, string &str1, string &str2, vector<vector<int>> &dp) {
        if(i==0 || j==0)    return 0;
        if(dp[i][j] != -1)  return dp[i][j];
        
        int cost = 0;
        if(str1[i-1] == str2[j-1])
            cost = 1 + lcs(i-1,j-1,str1,str2,dp);
        else
            cost = max(lcs(i-1,j,str1,str2,dp), lcs(i,j-1,str1,str2,dp));
        return dp[i][j] = cost; 
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return lcs(n,m,text1,text2,dp);
    }
};
