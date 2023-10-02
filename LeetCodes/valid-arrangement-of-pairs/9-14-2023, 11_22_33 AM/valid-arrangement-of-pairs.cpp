// Link: https://leetcode.com/problems/valid-arrangement-of-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-arrangement-of-pairs
 *  RUNTIME: 676 ms
 *  MEMORY: 275.3 MB
 *  DATE: 9-14-2023, 11:22:33 AM
 *
 */

// Solution:

class Solution {
public:
    void dfs(int node, int par, unordered_map<int, vector<int>> &adj, vector<vector<int>> &ans) {
        while(!adj[node].empty()) {
            int next = adj[node].back();
            adj[node].pop_back();
            dfs(next, node, adj, ans);
        }

        if(par != -1) {
            ans.push_back({par, node});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> deg;
        vector<vector<int>> ans;

        for(auto &x: pairs) {
            adj[x[0]].push_back(x[1]);
            deg[x[0]]++;
            deg[x[1]]--;
        }

        for(auto &x: adj) {
            sort(x.second.rbegin(), x.second.rend());
        }

        int start = pairs[0][0];
        for(auto &x: deg) {
            if(x.second > 0) {
                start = x.first;
            }
        }

        dfs(start, -1, adj, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
