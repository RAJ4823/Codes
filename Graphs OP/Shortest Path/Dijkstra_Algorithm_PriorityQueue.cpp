//? https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

//? TC = O(E * logV)
class Solution
{
public:
    //! Problem : Find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Priority queue is used to get minimum {dist, node} for each iteration
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minDist(V, 1e9);

        pq.push({0, S});
        minDist[S] = 0;

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Traverse each adjecent node of 'node'
            for (auto &edge : adj[node])
            {
                int neigh = edge[0];
                int weight = edge[1];

                if (dist + weight < minDist[neigh])
                {
                    minDist[neigh] = dist + weight;
                    pq.push({minDist[neigh], neigh});
                }
            }
        }
        return minDist;
    }
};

//! For understanding variables
// dist = minimum distance of parent node 'node' from source 'S'
// weight = distance of adj node 'neigh' from parent node 'node'
// Example : S --(2)-- P --(3)-- U --(1)-- V
// For node 'V' : dist = 5 and weight = 1

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends