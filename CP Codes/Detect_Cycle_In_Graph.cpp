#include <bits/stdc++.h>
using namespace std;

// Function to detect cycle in an undirected graph.
bool dfs(vector<int> g[], bool vis[], int vertex, int par)
{
    vis[vertex] = true;
    bool ans = false;
    for (auto child : g[vertex])
    {
        //Avoiding the condition of going to parent node
        if (vis[child] && child == par)
            continue;
        if (vis[child])
            return true;

        //ORing the boolean answer of each subGraph
        ans |= dfs(g, vis, child, vertex);
    }
    return ans;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    bool vis[V + 10];
    for (int i = 0; i <= V; i++)
        vis[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (vis[i])
            continue;
        if (dfs(adj, vis, i, -1))
            return true;
    }
    return false;
}

// { Driver Code Starts.
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
        bool ans = isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends