// Link: https://leetcode.com/problems/decode-ways

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: decode-ways
 *  RUNTIME: 4 ms
 *  MEMORY: 7 MB
 *  DATE: 12-25-2023, 9:19:06 PM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, string &s, vector<int> &dp) {
        if(i == s.size()) return 1;
        if(i > s.size()) return 0;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int take_one = find(i + 1, s, dp);
        int take_two = 0;
        if(i < s.size() - 1 && stoi(s.substr(i, 2)) <= 26) {
            take_two = find(i + 2, s, dp);
        }
        return dp[i] = take_one + take_two;
    }

    int numDecodings(string s) {
        int n = s.size();
        if(n == 1) return s[0] != '0';
        vector<int> dp(200, -1);
        return find(0, s, dp);
    }
};
