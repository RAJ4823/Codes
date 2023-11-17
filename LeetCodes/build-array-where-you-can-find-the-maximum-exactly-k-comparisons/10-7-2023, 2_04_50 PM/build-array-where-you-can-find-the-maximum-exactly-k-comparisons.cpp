// Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: build-array-where-you-can-find-the-maximum-exactly-k-comparisons
 *  RUNTIME: 15 ms
 *  MEMORY: 7.4 MB
 *  DATE: 10-7-2023, 2:04:50 PM
 *
 */

// Solution:

class Solution {
    public:
        int numOfArrays(int n, int m, int k) {
                const int mod = 1e9 + 7;

                        vector<vector<int>> dp(m+1, vector<int>(k+1, 0));
                                vector<vector<int>> prefix(m+1, vector<int>(k+1, 0));
                                        vector<vector<int>> prevDp(m+1, vector<int>(k+1, 0));
                                                vector<vector<int>> prevPrefix(m+1, vector<int>(k+1, 0));

                                                        for (int j = 1; j <= m; j++) {
                                                                    prevDp[j][1] = 1;
                                                                                prevPrefix[j][1] = j;
                                                                                        }

                                                                                                for (int _ = 2; _ <= n; _++) {
                                                                                                            dp.assign(m+1, vector<int>(k+1, 0));
                                                                                                                        prefix.assign(m+1, vector<int>(k+1, 0));

                                                                                                                                    for (int maxNum = 1; maxNum <= m; maxNum++) {
                                                                                                                                                    for (int cost = 1; cost <= k; cost++) {
                                                                                                                                                                        dp[maxNum][cost] = (static_cast<long long>(maxNum) * prevDp[maxNum][cost]) % mod;
                                                                                                                                                                                            
                                                                                                                                                                                                                if (maxNum > 1 && cost > 1) {
                                                                                                                                                                                                                                        dp[maxNum][cost] = (dp[maxNum][cost] + prevPrefix[maxNum - 1][cost - 1]) % mod;
                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]) % mod;
                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                            prevDp = dp;
                                                                                                                                                                                                                                                                                                                                                        prevPrefix = prefix;
                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                        return prefix[m][k];
                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                            };


