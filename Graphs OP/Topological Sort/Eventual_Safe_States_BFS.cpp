//? https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
//? https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //! Approach: By reversing each directed edge and calculating indegree of each node
    //! Then applying the topo sort (BFS) we can get the nodes whose outgoing degree is 0
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> adjRev[V]; // Reverse Adj. List
        vector<int> ind(V, 0); // Indegree of node
        for (int i = 0; i < V; i++)
        {
            for (auto &x : adj[i])
            {
                // *Given: i -> x
                //* Reverse: x -> i
                adjRev[x].push_back(i);
                ind[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }

        vector<int> safeNodes; // For storing safe Nodes
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);
            for (auto &x : adjRev[node])
            {
                ind[x]--;
                if (ind[x] == 0)
                    q.push(x);
            }
        }

        // Sort the safeNodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
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
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends