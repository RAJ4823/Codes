// Link: https://leetcode.com/problems/shortest-cycle-in-a-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-cycle-in-a-graph
 *  RUNTIME: 573 ms
 *  MEMORY: 153 MB
 *  DATE: 4-1-2023, 8:48:22 PM
 *
 */

// Solution:

class Solution
{
public:
    int minlen = INT_MAX;
    int MAX = 1e9;
    
    void dfs(int node, vector<int> graph[], vector<int> &path, vector<bool> &vis)
    {
        if (node == -1)
            return;

        if (vis[node])
        {
            int templen = 0, pathlen = path.size();
            for (auto &x : path)
            {
                if (x == node)
                {
                    minlen = min(minlen, pathlen - templen);
                    return;
                }
                templen++;
            }
            return;
        }

        vis[node] = true;
        path.push_back(node);
        for (auto &next : graph[node])
        {
            dfs(next, graph, path, vis);
        }

        return;
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> graph[n];
        

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // vector<bool> vis(n, false);
        // for (int i = 0; i < n; i++)
        // {
        //     if (!vis[i])
        //     {
        //         vector<int> path;
        //         dfs(i, graph, path, vis);
        //     }
        // }

        for (int i = 0; i < n; i++)
        {
            vector<int> par(n, -1);
            vector<int> vis(n, MAX);
            
            queue<int> q;
            q.push(i);
            vis[i] = 0;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                
                for (auto &next: graph[curr])
                {
                    if (vis[next] == MAX)
                    {
                        vis[next] = 1 + vis[curr];
                        par[next] = curr;
                        q.push(next);
                    }
                    else if (par[curr] != next && par[next] != curr)
                    {
                        int len = vis[curr] + vis[next] + 1;
                        minlen = min(minlen, len);
                    }
                        
                }
            }
        }

        if (minlen == INT_MAX)
            return -1;
        else
            return minlen;
    }
};
