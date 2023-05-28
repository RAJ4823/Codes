//? https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
//* Defination: To find the total number of "STRONGLY CONNECTED COMPONENTS" in Directed Graph.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs_store(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = true;
        for (auto &next : adj[node])
            if (!vis[next])
                dfs_store(next, vis, adj, st);
        st.push(node);
    }

    void dfs_visit(int node, vector<bool> &vis, vector<vector<int>> &rev_adj)
    {
        vis[node] = true;
        for (auto &next : rev_adj[node])
            if (!vis[next])
                dfs_visit(next, vis, rev_adj);
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<vector<int>> rev_adj(V); // for storing reverse adjacency list
        vector<bool> vis(V, false);     // for marking visited nodes
        stack<int> st;                  // for storing nodes by the finising time (reverse order of visited nodes)

        //! STEP 1: Store nodes by their finishing time into the stack
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs_store(i, vis, adj, st);
            }
        }

        //! STEP 2: Reverse the graph (all edges)
        for (int i = 0; i < V; i++)
        {
            vis[i] = false;
            for (auto node : adj[i])
            {
                rev_adj[node].push_back(i);
            }
        }

        //! STEP 3: Count connected components using DFS
        int SCC = 0;
        while (!st.empty())
        {
            int i = st.top();
            st.pop();

            if (!vis[i])
            {
                dfs_visit(i, vis, rev_adj);
                SCC++;
            }
        }
        return SCC;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends