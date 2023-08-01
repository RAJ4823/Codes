// Link: https://leetcode.com/problems/restore-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-the-array
 *  RUNTIME: 98 ms
 *  MEMORY: 21.9 MB
 *  DATE: 4-23-2023, 10:17:05 AM
 *
 */

// Solution:

class Solution {
public:
    long long maxVal = 0, len = 0;
    long long mod = 1000000007;
    vector<int> dp;
    int find(int i, string &s) {
        if(i == len) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        long long count = 0, num = 0;
        for(int j = i; j < len; j++) {
            num = num*10 + (s[j] - '0');
            if(num > maxVal) break;
            count = (count % mod + find(j+1, s) % mod) % mod;
        }
        return dp[i] = count % mod;
    }
    int numberOfArrays(string s, int k) {
        maxVal = k;
        len = s.length();
        dp.resize(len, -1);
        return find(0, s);
    }
};
