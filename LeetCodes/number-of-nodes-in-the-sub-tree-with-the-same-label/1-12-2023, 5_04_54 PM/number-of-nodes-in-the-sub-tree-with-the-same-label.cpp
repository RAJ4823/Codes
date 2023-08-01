// Link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-nodes-in-the-sub-tree-with-the-same-label
 *  RUNTIME: 640 ms
 *  MEMORY: 219.3 MB
 *  DATE: 1-12-2023, 5:04:54 PM
 *
 */

// Solution:

class Solution {
public:

    void dfs (int node, int prev, vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int> &ans, string &labels) {
        int ch = labels[node]-'a';
        dp[node][ch]++;

        for (auto &child: adj[node]) {
            if (child != prev) {
                dfs(child, node, adj, dp, ans, labels);
                for (int i=0; i<27; i++) {
                    dp[node][i] += dp[child][i];
                }
            }
        }
        ans[node] = dp[node][ch];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector <vector<int>> dp(n, vector<int>(27, 0));
        vector<vector<int>> adj(n);
        vector<int> ans(n);

        for (auto &data: edges) {
            adj[data[0]].push_back(data[1]);
            adj[data[1]].push_back(data[0]);
        }

        dfs(0, -1, adj, dp, ans, labels);
        return ans;
    }
};
