// Link: https://leetcode.com/problems/path-with-maximum-probability

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-with-maximum-probability
 *  RUNTIME: 222 ms
 *  MEMORY: 68.9 MB
 *  DATE: 6-28-2023, 8:53:34 AM
 *
 */

// Solution:

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], prob[i]});
            graph[edges[i][1]].push_back({edges[i][0], prob[i]});
        }

        queue<pair<int,double>> q;
        vector<double> vis(n, 0);
    
        q.push({start, 1});
        vis[start] = true;

        while(!q.empty()) {
            int node = q.front().first;
            double currProb = q.front().second;
            q.pop();   

            for(auto &x: graph[node]) {
                int next = x.first;
                double newProb = currProb * x.second;
                if(newProb > vis[next]) {
                    vis[next] = newProb;
                    q.push({next, newProb});
                }
            }
        }
        return vis[end];
    }
};
