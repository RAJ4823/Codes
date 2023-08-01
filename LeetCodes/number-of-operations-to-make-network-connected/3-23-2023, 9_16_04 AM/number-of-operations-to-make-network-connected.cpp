// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-operations-to-make-network-connected
 *  RUNTIME: 149 ms
 *  MEMORY: 68 MB
 *  DATE: 3-23-2023, 9:16:04 AM
 *
 */

// Solution:

class Solution {
public:
    int countExtraEdges(int source, vector<vector<int>>& graph, vector<bool> &vis) {
        queue<pair<int,int>> q;
        q.push({source, -1});
        vis[source] = true;

        int edges = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto &next: graph[node]) {
                if(!vis[next]) {
                    q.push({next, node});
                    vis[next] = true;
                } else if(par != next) {
                    edges++;
                }
            }
        }
        return edges;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<int>> graph(n);
        for(auto &edge: connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int extraEdges = 0, components = 0;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                components++;
                extraEdges += countExtraEdges(i, graph, vis);
            }
        }
        if(components == 1)
            return 0;
        else if(components - 1 < extraEdges) 
            return components - 1;
        return -1;
    }
};
