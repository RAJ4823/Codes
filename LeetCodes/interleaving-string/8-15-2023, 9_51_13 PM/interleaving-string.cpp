// Link: https://leetcode.com/problems/interleaving-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: interleaving-string
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 8-15-2023, 9:51:13 PM
 *
 */

// Solution:

class Solution {
public:
    int n, m;
    bool find(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        if(i == n) {
            for(int k=j; k<m; k++) {
                if(s3[i+k] != s2[k]) return false;
            }
            return true;
        }
        if(j == m) {
            for(int k=i; k<n; k++) {
                if(s3[j+k] != s1[k]) return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        bool take1 = false, take2 = false;
        if(s1[i] == s3[i+j]) {
            take1 = true && find(i+1, j, s1, s2, s3, dp);
        }
        if(s2[j] == s3[i+j]) {
            take2 = true && find(i, j+1, s1, s2, s3, dp);
        }
        return dp[i][j] = (take1 || take2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if(n + m != s3.size()) return false;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));

        return find(0, 0, s1, s2, s3, dp);
    }
};
