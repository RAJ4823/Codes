//? https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check_dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
    {
        // Mark visited and pathVisited true for current node
        vis[node] = true;
        path[node] = true;

        // Traverse for adjacent/neighbour nodes
        for (auto neigh : adj[node])
        {
            if (!vis[neigh])
            {
                // If neigh node is not visited check for cycle by calling dfs for it
                // If we get true that means there is a cycle so return true
                if (check_dfs(neigh, adj, vis, path))
                    return true;
            }
            // If node is visited than check for path visited
            else if (path[neigh])
            {
                // If node is path visited also than there is a cycle, return true
                return true;
            }
        }

        // If there is no cycle for node mark pathVisited false for node and return false
        path[node] = false;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++)
        {
            if (check_dfs(i, adj, vis, path))
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends