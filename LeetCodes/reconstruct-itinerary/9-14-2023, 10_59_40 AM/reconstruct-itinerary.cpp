// Link: https://leetcode.com/problems/reconstruct-itinerary

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reconstruct-itinerary
 *  RUNTIME: 14 ms
 *  MEMORY: 14.5 MB
 *  DATE: 9-14-2023, 10:59:40 AM
 *
 */

// Solution:

class Solution {
public:
    void dfs(string &start, unordered_map<string, vector<string>> &adj, vector<string> &ans) {
        while(!adj[start].empty()) {
            string next = adj[start].back();
            adj[start].pop_back();
            dfs(next, adj, ans);
        }

        ans.push_back(start);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        vector<string> ans;
        for(auto &x: tickets) {
            adj[x[0]].push_back(x[1]);
        }

        for(auto &x: adj) {
            sort(x.second.rbegin(), x.second.rend());
        }

        string start = "JFK";
        dfs(start, adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
