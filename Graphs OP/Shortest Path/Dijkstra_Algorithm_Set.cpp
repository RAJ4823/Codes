//? https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
using namespace std;

//? TC = O(E * logV)
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> minDist(V, 1e9);

        st.insert({0, S});
        minDist[S] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            st.erase(it);

            for (auto &edge : adj[node])
            {
                int neigh = edge[0];
                int weight = edge[1];

                if (dist + weight < minDist[neigh])
                {
                    // If its already present then erase it since current 'neigh' gives minimum distance
                    if (minDist[neigh] != 1e9)
                        st.erase({minDist[neigh], neigh});

                    minDist[neigh] = dist + weight;
                    st.insert({minDist[neigh], neigh});
                }
            }
        }
        return minDist;
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