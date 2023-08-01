// Link: https://leetcode.com/problems/is-graph-bipartite

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: is-graph-bipartite
 *  RUNTIME: 40 ms
 *  MEMORY: 13.4 MB
 *  DATE: 12-3-2022, 9:33:35 AM
 *
 */

// Solution:

class Solution {
private:

    //! BFS Approach
    // bool check_bfs(int s, vector<vector<int>> &adj, vector<int> &color)
    // {
    //     queue<int> q;
    //     color[s] = 0;
    //     q.push(s);

    //     while (!q.empty())
    //     {
    //         int node = q.front();
    //         q.pop();

    //         for (auto neigh : adj[node])
    //         {
    //             if (color[neigh] == -1)
    //             {
    //                 color[neigh] = !color[node];
    //                 q.push(neigh);
    //             }
    //             else if (color[neigh] == color[node])
    //             {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    //! DFS Approach
    bool check_dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
    {
        color[node] = col;
        for (auto neigh : adj[node])
        {
            if (color[neigh] == -1)
            {
                if (check_dfs(neigh, !col, adj, color) == false)
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
                // if (check_bfs(i, adj, color) == false)
                //     return false;
                if (check_dfs(i, 0, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};
