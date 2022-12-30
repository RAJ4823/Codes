//? https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

//* Algorithm: By relaxing all edges (V-1) times sequentially, We can get the shortest paths from 'single' source node
//* Detecting Negative Cycle: If relaxation of edges done one more time (Vth time), And it reduces distance that means there is a negative cycle                        
//? TC = O(E * V)

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                //! Relaxation of Edges : reducing distance to reach node v
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            //! If dist reduces that means there is negative cycle
            if (dist[u] + w < dist[v])
                return {-1};
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
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends