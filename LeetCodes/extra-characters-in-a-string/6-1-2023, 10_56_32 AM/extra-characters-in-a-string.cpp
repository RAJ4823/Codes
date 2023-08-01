// Link: https://leetcode.com/problems/extra-characters-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: extra-characters-in-a-string
 *  RUNTIME: 200 ms
 *  MEMORY: 64.1 MB
 *  DATE: 6-1-2023, 10:56:32 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int n, string &s, vector<int> &dp, set<string> &st) {
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = 1e9, nottake = 1e9;
        string temp = "";

        nottake = 1 + find(i+1, n, s, dp, st);
        for(int j=i; j<s.size(); j++) {
            temp += s[j];
            if(st.find(temp) != st.end()) 
                take = min(take, find(j+1, n, s, dp, st));
        }
        return dp[i] = min(take, nottake);
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> dp(n, -1);
        set<string> st(dict.begin(), dict.end());
        return find(0, n, s, dp, st);
    }
};
