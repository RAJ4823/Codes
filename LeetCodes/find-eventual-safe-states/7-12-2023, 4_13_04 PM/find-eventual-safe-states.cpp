// Link: https://leetcode.com/problems/find-eventual-safe-states

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-eventual-safe-states
 *  RUNTIME: 188 ms
 *  MEMORY: 48.3 MB
 *  DATE: 7-12-2023, 4:13:04 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> vis, path, safe;
    bool dfs(int node, vector<vector<int>> &adj) {
        vis[node] = path[node] = true;
        safe[node] = false;

        for(auto &next: adj[node]) {
            if(!vis[next]) {
                if(dfs(next, adj)) return true;
            } else if(path[next]) {
                return true;
            }
        }

        safe[node] = true;
        path[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vis.resize(n, false);
        path.resize(n, false);
        safe.resize(n, false);
        vector<int> ans;

        for(int i=0; i<n; i++) dfs(i, adj);
        for(int i=0; i<n; i++) {
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};
