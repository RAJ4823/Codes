//? https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

//! If we want to print MST then use {edgeWeight, Node, ParentNode} structure in priority_queue and If node is not visited then visit it and push it to MST ( {node, parent} );
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(V, false);

        pq.push({0, 0});
        int totalWeight = 0;

        while (!pq.empty())
        {
            // Pick the node with minimum edgeWeight (here we used minHeap)
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();

            // If node is not visited then visit it
            if (!vis[node])
            {
                vis[node] = true;
                totalWeight += weight;

                // Traverse it's neighbour nodes
                for (auto &data : adj[node])
                {
                    int neighNode = data[0];
                    int edgeWeight = data[1];

                    // If node is not visited then push its data to pq
                    if (!vis[neighNode])
                    {
                        pq.push({edgeWeight, neighNode});
                    }
                }
            }
        }

        return totalWeight;
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

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends