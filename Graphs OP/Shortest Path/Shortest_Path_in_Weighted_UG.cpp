//? https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        pq.push({0, 1});
        dist[1] = 0;

        // Simple Dijkstra Algorithm
        while (!pq.empty())
        {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &edge : adj[node])
            {
                int neigh = edge.first;
                int weight = edge.second;

                if (nodeDist + weight < dist[neigh])
                {
                    dist[neigh] = nodeDist + weight;
                    pq.push({dist[neigh], neigh});
                    parent[neigh] = node;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        // Backtracking the parent array to print path
        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main()
{
    // your code goes here
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