// Link: https://leetcode.com/problems/extra-characters-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: extra-characters-in-a-string
 *  RUNTIME: 163 ms
 *  MEMORY: 63 MB
 *  DATE: 9-2-2023, 9:48:49 AM
 *
 */

// Solution:

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        set<string> st(dict.begin(), dict.end());

        for(int i=n-1; i>= 0; i--) {
            int take = 1e9;

            string str = "";
            for(int j=i; j<n; j++) {
                str += s[j];
                if(st.find(str) != st.end()) {
                    take = min(take, dp[j+1]);
                }
            }
            dp[i] = min(1 + dp[i+1], take);
        }
        return dp[0];
    }
};
