// Link: https://leetcode.com/problems/is-graph-bipartite

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: is-graph-bipartite
 *  RUNTIME: 34 ms
 *  MEMORY: 13.6 MB
 *  DATE: 5-19-2023, 10:38:07 AM
 *
 */

// Solution:

class Solution {
private:
    bool check_dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
    {
        color[node] = col;
        for (auto neigh: adj[node])
        {
            if (color[neigh] == -1)
            {
                if (!check_dfs(neigh, !col, adj, color))
                    return false;
            }
            else if (color[neigh] == color[node])
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!check_dfs(i, 0, adj, color))
                    return false;
            }
        }
        return true;
    }
};
