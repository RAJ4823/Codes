// Link: https://leetcode.com/problems/parallel-courses-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: parallel-courses-iii
 *  RUNTIME: 321 ms
 *  MEMORY: 132.1 MB
 *  DATE: 10-18-2023, 11:44:23 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0), maxTime(n, 0);
        int m = relations.size();
        for(int i=0; i<m; i++) {
            int u = relations[i][0] - 1;
            int v = relations[i][1] - 1;
            adj[u].push_back(v);
            deg[v]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(deg[i] == 0) {
                q.push(i);
                maxTime[i] = time[i];
            }
        }

        int minTime = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            minTime = max(minTime, maxTime[node]);

            for(auto &next: adj[node]) {
                deg[next]--;
                maxTime[next] = max(maxTime[next], maxTime[node] + time[next]);
                if(deg[next] == 0) {
                    q.push(next);
                }
            }
        }
        return minTime;
    }
};
