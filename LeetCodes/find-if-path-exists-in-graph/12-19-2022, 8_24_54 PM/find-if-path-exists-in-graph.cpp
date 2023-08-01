// Link: https://leetcode.com/problems/find-if-path-exists-in-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-if-path-exists-in-graph
 *  RUNTIME: 942 ms
 *  MEMORY: 247.7 MB
 *  DATE: 12-19-2022, 8:24:54 PM
 *
 */

// Solution:

class Solution {
private: 
    bool dfs(int node, int dest, unordered_map<int,vector<int>> &adj, vector<bool> &vis) {
        if(node == dest) return true;
        vis[node] = true;

            for(auto &neigh : adj[node]) {
                if(!vis[neigh] && dfs(neigh, dest, adj, vis)) {
                    return true;
                }
            }
        
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n);
        return dfs(source, destination, adj, vis);
    }
};
