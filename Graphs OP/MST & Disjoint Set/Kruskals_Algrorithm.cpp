//? https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

// Using DisjointSet Class from previous Code
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int root_u = findUPar(u); // Ultimate parent of 'u'
        int root_v = findUPar(v); // Ultimate parent of 'v'

        if (root_u == root_v)
            return;
        if (rank[root_u] < rank[root_v])
            parent[root_u] = root_v;
        else if (rank[root_u] > rank[root_v])
            parent[root_v] = root_u;
        else
        {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }

    // Size is the total number of nodes
    void unionBySize(int u, int v)
    {
        int root_u = findUPar(u); // Ultimate parent of 'u'
        int root_v = findUPar(v); // Ultimate parent of 'v'

        if (root_u == root_v)
            return;
        if (size[root_u] < size[root_v])
        {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else
        {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> data(n);
        // {weight, {u, v}}

        for (int u = 0; u < n; u++)
        {
            for (auto &edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];
                data.push_back({w, {u, v}});
            }
        }
        // Sort the data by weight
        sort(data.begin(), data.end());

        // create the disjoint set of 'n' nodes
        DisjointSet ds(n);
        int totalWeight = 0;

        for (auto &val : data)
        {
            int w = val.first;
            int u = val.second.first;
            int v = val.second.second;
            // We can print MST by using 'u' and 'v' 
            // If ulimate parent of 'u' and 'v' is not same then 
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                // combine both nodes into one component
                ds.unionBySize(u, v);
                // add its edgeWeight to totalWeight
                totalWeight += w;
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