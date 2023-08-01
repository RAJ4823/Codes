// Link: https://leetcode.com/problems/tallest-billboard

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: tallest-billboard
 *  RUNTIME: 1469 ms
 *  MEMORY: 162.5 MB
 *  DATE: 6-24-2023, 9:14:30 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, int a, int b, vector<int> &rods, unordered_map<string, int> &dp) {
        if(i >= rods.size()) {
            return (a == b) ? a : -1;
        }
        string key = to_string(i) + '|' + to_string(abs(a - b));
        if(dp.find(key) != dp.end()) {
            if(dp[key] != -1) 
                return max(a, b) + dp[key];
            return -1;
        }

        int take1 = find(i+1, a + rods[i], b, rods, dp);
        int take2 = find(i+1, a, b + rods[i], rods, dp);
        int nottake = find(i+1, a, b, rods, dp);
        int ans = max({take1, take2, nottake});
        dp[key] = ans == -1 ? -1 : ans - max(a, b);
        return ans;
    }
    int tallestBillboard(vector<int>& rods) {
        unordered_map<string, int> dp;
        return find(0, 0, 0, rods, dp);
    }
};
