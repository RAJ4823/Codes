// Link: https://leetcode.com/problems/maximum-path-quality-of-a-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-path-quality-of-a-graph
 *  RUNTIME: 160 ms
 *  MEMORY: 21 MB
 *  DATE: 9-4-2023, 9:27:42 AM
 *
 */

// Solution:

class Solution {
public:
    int ans, N, MAX_TIME;
    void dfs(int node, int sum, int time, vector<vector<pair<int,int>>> &adj, vector<int> &vis, vector<int> &values) {
        if(time > MAX_TIME) return;

        if(vis[node] == 0)  sum += values[node];
        if(node == 0)       ans = max(ans, sum);
        
        vis[node]++;
        for(auto &x: adj[node]) {
            int next = x.first;
            int newTime = x.second + time;
            dfs(next, sum, newTime, adj, vis, values);
        }
        vis[node]--;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        N = values.size();
        MAX_TIME = maxTime;
        ans = values[0];
        vector<vector<pair<int,int>>> adj(N);
        vector<int> vis(N, 0);

        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        dfs(0, 0, 0, adj, vis, values);
        return ans;
    }
};
