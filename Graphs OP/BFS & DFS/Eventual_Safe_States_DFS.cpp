//? https://practice.geeksforgeeks.org/problems/eventual-safe-states/
//? https://leetcode.com/problems/find-eventual-safe-states/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check_dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path, vector<bool> &isSafe)
    {
        // Mark visited and pathVisited true for current node
        vis[node] = true;
        path[node] = true;
        isSafe[node] = false;
        // Traverse for adjacent/neighbour nodes
        for (auto neigh : adj[node])
        {
            if (!vis[neigh])
            {
                // If neigh node is not visited check for cycle by calling dfs for it
                // If we get true that means there is a cycle so return true
                if (check_dfs(neigh, adj, vis, path, isSafe))
                    return true;
            }
            // If node is visited than check for path visited
            else if (path[neigh])
            {
                // If node is path visited also than there is a cycle, return true
                return true;
            }
        }

        // If there is no cycle for node mark it path visited false
        // And make isSafe true as this node is safe node
        isSafe[node] = true;
        path[node] = false;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false), path(V, false), isSafe(V, false);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++)
            check_dfs(i, adj, vis, path, isSafe);
        for (int i = 0; i < V; i++)
            if (isSafe[i])
                safeNodes.push_back(i);
        return safeNodes;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends