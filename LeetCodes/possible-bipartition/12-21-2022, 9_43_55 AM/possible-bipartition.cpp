// Link: https://leetcode.com/problems/possible-bipartition

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: possible-bipartition
 *  RUNTIME: 268 ms
 *  MEMORY: 63.7 MB
 *  DATE: 12-21-2022, 9:43:55 AM
 *
 */

// Solution:

class Solution {
private:
    bool check_dfs(int node, int col, vector<int> graph[], vector<int> &color) {
        color[node] = col;
        for (auto neigh : graph[node]) {
            if (color[neigh] == -1) {
                if (!check_dfs(neigh, !col, graph, color))
                    return false;
            }
            else if (color[neigh] == color[node]) {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n];
        for(auto &edge: dislikes) {
            int u = edge[0]-1;
            int v = edge[1]-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n, -1);
        //Checking for all components of graphs
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!check_dfs(i, 0, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
