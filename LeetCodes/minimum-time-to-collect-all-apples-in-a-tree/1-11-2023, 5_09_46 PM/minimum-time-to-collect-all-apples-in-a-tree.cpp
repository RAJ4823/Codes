// Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-to-collect-all-apples-in-a-tree
 *  RUNTIME: 171 ms
 *  MEMORY: 60.9 MB
 *  DATE: 1-11-2023, 5:09:46 PM
 *
 */

// Solution:

class Solution {
private:
    int dfs(int node, vector<int> adj[], vector<int> &vis) {
        if(vis[node]) return 0;
        vis[node] = true;
        return 2 + dfs(adj[node][0], adj, vis);
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n], vis(n, false);
        for(auto &data: edges) {
            int u = data[0];
            int v = data[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        int ans = 0;
        vis[0] = true;
        for(int i=0; i<n; i++) {
            if(!vis[i] && hasApple[i]) {
                ans += dfs(i, adj, vis);
            }
        }
        return ans;
    }
};
