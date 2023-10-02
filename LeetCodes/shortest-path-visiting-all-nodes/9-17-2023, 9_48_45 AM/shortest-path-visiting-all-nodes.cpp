// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-path-visiting-all-nodes
 *  RUNTIME: 108 ms
 *  MEMORY: 17.8 MB
 *  DATE: 9-17-2023, 9:48:45 AM
 *
 */

// Solution:

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        set<pair<int,int>> vis;

        int all_vis_mask = (1 << n) - 1;

        for(int i=0; i<n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            vis.insert({i, mask});
        }

        int len = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();

                if(mask == all_vis_mask) {
                    return len;
                } 

                for(auto &next: graph[node]) {
                    int newMask = mask | (1 << next);
                    if(vis.find({next, newMask}) == vis.end()) {
                        vis.insert({next, newMask});
                        q.push({next, newMask});
                    }
                }
            }
            len++;
        }
        return 0;
    }
};
