//* https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

//? TC = O(V + 2E) , SC = O(V)
class Solution
{
private:
    //! Using  BFS
    bool detect_bfs(int src, vector<int> adj[], vector<bool> &vis)
    {
        queue<pair<int, int>> q;
        vis[src] = true;
        // { current_node , parent_node }
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto x : adj[node])
            {
                if (!vis[x])
                {
                    vis[x] = true;
                    q.push({x, node});
                }
                else if (parent != x)
                {
                    // Two different nodes (having different parents) visited same node x
                    // Which means there is a cycle
                    return true;
                }
            }
        }
        return false;
    }

    //! Using DFS
    bool detect_dfs(int node, int parent, vector<int> adj[], vector<bool> &vis)
    {
        vis[node] = true;
        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                // If already found a cycle return true
                if (detect_dfs(x, node, adj, vis))
                    return true;
            }
            else if (x != parent)
            {
                // node x is already visited and its not a parent node
                // Which means there is a cycle
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                // if(detect_bfs(i,adj,vis))
                // return true;
                if (detect_dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends