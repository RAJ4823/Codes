// Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-score-of-a-path-between-two-cities
 *  RUNTIME: 535 ms
 *  MEMORY: 127.6 MB
 *  DATE: 3-22-2023, 9:36:05 AM
 *
 */

// Solution:

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> g[n+1];
        vector<bool> vis(n+1, false);
        queue<pair<int,int>> q;

        for(auto &road: roads) {
            g[road[0]].push_back({road[1], road[2]});
            g[road[1]].push_back({road[0], road[2]});
        }

        for(auto &x: g[1]) {
            q.push(x);
        }
        vis[1] = true;
        int minDist = INT_MAX;
        while(!q.empty()) {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            minDist = min(dist, minDist);

            for(auto &x: g[node]) {
                int next = x.first;
                int d = x.second;

                if(!vis[next]) {
                    q.push({next, d});
                    // vis[next] = true;
                }
            }
            vis[node] = true;
        }
        return minDist;
    }
};
