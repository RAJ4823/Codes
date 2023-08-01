// Link: https://leetcode.com/problems/course-schedule

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: course-schedule
 *  RUNTIME: 29 ms
 *  MEMORY: 12.8 MB
 *  DATE: 7-13-2023, 9:48:02 AM
 *
 */

// Solution:

class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], ind(n, 0);
        queue<int> q;

        for(auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            ind[edge[1]]++;
        }

        for(int i=0; i<n; i++) {
            if(ind[i] == 0) {
                q.push(i);
            }
        }

        int vis = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vis++;

            for(auto &next: adj[node]) {
                if(--ind[next] == 0) {
                    q.push(next);
                }
            }
        }

        return vis == n;
    }
};
