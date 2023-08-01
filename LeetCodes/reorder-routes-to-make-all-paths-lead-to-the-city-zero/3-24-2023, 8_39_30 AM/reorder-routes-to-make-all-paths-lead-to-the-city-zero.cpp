// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reorder-routes-to-make-all-paths-lead-to-the-city-zero
 *  RUNTIME: 415 ms
 *  MEMORY: 106 MB
 *  DATE: 3-24-2023, 8:39:30 AM
 *
 */

// Solution:

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> graph[n], org[n];
        for(auto &edge: connections) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            org[u].push_back(v);
        }

        queue<int> q;
        vector<int> vis(n, false);
        q.push(0);
        vis[0] = true;


        int countEdges = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &next: org[node]) {
                if(!vis[next]) {
                    countEdges++;
                }
            }

            for(auto &next: graph[node]) {
                if(!vis[next]) {
                    q.push(next);
                    vis[next] = true;
                }
            }
        }
        return countEdges;
    }
};
