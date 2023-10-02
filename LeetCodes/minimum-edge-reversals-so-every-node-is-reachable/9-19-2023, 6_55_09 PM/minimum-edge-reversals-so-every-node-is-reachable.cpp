// Link: https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-edge-reversals-so-every-node-is-reachable
 *  RUNTIME: 380 ms
 *  MEMORY: 195.8 MB
 *  DATE: 9-19-2023, 6:55:09 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> vis, cost, depth;
    vector<vector<pair<int,int>>> adj;
    int totalCost = 0;
    
    void dfs(int node, int d) {
        vis[node] = true;
        depth[node] = d;
        
        for(auto &x: adj[node]) {
            int next = x.first;
            int weight = x.second;
            
            if(!vis[next]) {
                cost[next] = cost[node] + weight;
                totalCost += weight;
                dfs(next, d + 1);
            }
        }
    }
    
    void init(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n);
        cost.resize(n);
        depth.resize(n);
        
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], 0});
            adj[edge[1]].push_back({edge[0], 1});
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        init(n, edges);
        dfs(0, 0);
        
        vector<int> ans(n);
        ans[0] = totalCost;
        for(int i=1; i<n; i++) {
            ans[i] = depth[i] - cost[i] + totalCost - cost[i];
        }
        return ans;
    }
};
