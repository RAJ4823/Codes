// Link: https://leetcode.com/problems/shortest-path-with-alternating-colors

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-path-with-alternating-colors
 *  RUNTIME: 16 ms
 *  MEMORY: 14.6 MB
 *  DATE: 2-11-2023, 1:28:06 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<pair<int,int>> adj[n];
        for(auto &x: blueEdges) {
            adj[x[0]].push_back({x[1], 0});
        }
        for(auto &x: redEdges) {
            adj[x[0]].push_back({x[1], 1});
        }

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> minDist(n, vector<int> (2, INT_MAX));

        minDist[0][0] = minDist[0][1] = 0;

        for(auto &x: adj[0]) {
            if(x.first == 0) continue;
            q.push({x, 1});
            minDist[x.first][x.second] = 1;
        }

        while(!q.empty()) {
            int node = q.front().first.first;
            int color = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(auto &x: adj[node]) {
                int neigh = x.first;
                int clr = x.second;

                if(clr != color && dist + 1 < minDist[neigh][clr]) {
                    minDist[neigh][clr] = dist+1;
                    q.push({x, dist+1});
                }
            }
        }

        vector<int> ans(n, -1);
        for(int i=0; i<n; i++) {
            int dist = min(minDist[i][0], minDist[i][1]);
            if(dist == INT_MAX) continue;
            ans[i] = dist;
        }
        return ans;
    }
};
