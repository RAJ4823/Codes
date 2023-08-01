// Link: https://leetcode.com/problems/longest-cycle-in-a-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-cycle-in-a-graph
 *  RUNTIME: 221 ms
 *  MEMORY: 135.3 MB
 *  DATE: 3-26-2023, 3:47:46 PM
 *
 */

// Solution:

class Solution {
public:
    int maxlen = -1;
    void dfs(int node, vector<int> &edges, vector<int> &path, vector<bool> &vis) {
        if(node == -1) return;

        if(vis[node]) {
            int templen = 0, pathlen = path.size();
            for(auto &x: path) {
                if(x == node) {
                    maxlen = max(maxlen, pathlen - templen);
                    return;
                }
                templen++;
            }
            return;
        }

        vis[node] = true;
        path.push_back(node);
        dfs(edges[node], edges, path, vis);

        return;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                vector<int> path;
                dfs(i, edges, path,vis);
            }
        }
        return maxlen;
    }
};
