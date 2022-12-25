//? https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

//? TC = O(V + E)
class Solution
{
private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[node] = true;
        for (auto &x : adj[node])
        {
            int neigh = x.first;
            if (!vis[neigh])
                topoSort(neigh, adj, vis, st);
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int v = edges[i][0]; // Node - v
            int u = edges[i][1]; // Node - u
            int w = edges[i][2]; // Weight of edge (v-u)
            adj[v].push_back({u, w});
        }

        // Create topoSort stack
        stack<int> st;
        vector<bool> vis(N, false);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        // Assign all dist[i] values to INF and dist[source] to 0
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Get top most node from stack iterate it's neigh. node
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto &x : adj[node])
            {
                int v = x.first;
                int w = x.second;

                // If ditsance from node to v is less then previous distance, update it
                if (dist[node] + w < dist[v])
                    dist[v] = dist[node] + w;
            }
        }

        // if any dist[i] is 1e9 update it to -1
        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }
        return dist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends