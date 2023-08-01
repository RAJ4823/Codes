// Link: https://leetcode.com/problems/restore-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-the-array
 *  RUNTIME: 274 ms
 *  MEMORY: 43.2 MB
 *  DATE: 4-23-2023, 10:15:47 AM
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

        int count = 0;
        string str = "";

        for(int j = i; j < len; j++) {
            str += s[j];
            if(stol(str) > maxVal) break;
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
