//? https://practice.geeksforgeeks.org/problems/bipartite-graph/1
//? https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:

    //! BFS Approach
    bool check_bfs(int s, vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
        color[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neigh : adj[node])
            {
                //Check for neigh node already colored or not
                if (color[neigh] == -1)
                {
                    //If neigh node is not colored yet, then color it by oposite color of node
                    color[neigh] = !color[node];
                    q.push(neigh);
                }
                else if (color[neigh] == color[node])
                {
                    //If neigh node is colored AND color of node and neigh node is same than return false
                    return false;
                }
            }
        }
        return true;
    }

    //! DFS Approach
    bool check_dfs(int node, int col, vector<int> adj[], vector<int> &color)
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
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        //Checking for all components of graphs
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

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends