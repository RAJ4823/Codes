// Link: https://leetcode.com/problems/critical-connections-in-a-network

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: critical-connections-in-a-network
 *  RUNTIME: 636 ms
 *  MEMORY: 180.5 MB
 *  DATE: 5-28-2023, 6:46:51 PM
 *
 */

// Solution:

class Solution {
public:
    // time = to store the time taken for ith node to be inserted (dfs)
    // low = to store the lowest time of ith node by which it can be visited through neighbours
    // vis = for marking visited nodes
    // crtcons = critical connections
    // adj = adjacency list
    vector<int> time, low, vis;
    vector<vector<int>> crtcons, adj;
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>> &adj) {
        vis[node] = true;
        time[node] = low[node] = timer++;

        for(auto &next: adj[node]) {
            if(next == parent) continue;
            if(!vis[next]) {
                dfs(next, node, adj);
                low[node] = min(low[node], low[next]);
                if(low[next] > time[node]) {
                    crtcons.push_back({node, next});
                }
            } else {
                low[node] = min(low[node], low[next]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& cons) {
        vis.resize(n, false);
        low.resize(n, INT_MAX);
        time.resize(n);
        adj.resize(n);

        for(auto &edge: cons) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj);
        return crtcons;
    }
};
