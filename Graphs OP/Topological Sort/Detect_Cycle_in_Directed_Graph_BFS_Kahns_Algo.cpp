//? https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
#include <bits/stdc++.h>
using namespace std;

//? TC = O(V + E)
class Solution
{

public:
    //! Kahn's Algorithm for Topo Sort is Used here
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0);
        queue<int> q;

        // Counting indegrees of all nodex
        for (int i = 0; i < V; i++)
        {
            for (auto x : adj[i])
                inDegree[x]++;
        }

        // Node having zero inderee will be the first (top most) node in sorting order
        // So push that node into the queue
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Counter for counting size of topo sort
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            count++;
            q.pop();

            for (auto neigh : adj[node])
            {
                // After visiting neigh node decrease the inderee of that node
                inDegree[neigh]--;
                // Push node into queue when its indegree becomes zero
                if (inDegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        // If the length (size) of the topo sort is equal to total vertex (N) Then there is no cycle
        if (count == V)
            return false;
        // There is a cycle, If size of topo sort is less than N
        return true;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends