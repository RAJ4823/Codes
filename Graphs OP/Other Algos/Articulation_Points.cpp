//? https://practice.geeksforgeeks.org/problems/articulation-point-1/
//* Defination: By removing a vertex if the graph becomes disconnected into multiple components then
//*             that vertex is called articulation point

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time = to store the time taken for ith node to be inserted (dfs)
    // low = to store the lowest time of ith node by which it can be visited through neighbours
    // vis = for marking visited nodes
    // isArtPoint = for marking articulation points
    // adj = adjacency list
    vector<int> time, low;

    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &isArtPoint)
    {
        vis[node] = true;
        time[node] = low[node] = timer++;
        int child = 0;
        for (auto &next : adj[node])
        {
            if (next == parent)
                continue;

            if (!vis[next])
            {
                dfs(next, node, adj, vis, isArtPoint);
                child++;

                low[node] = min(low[node], low[next]);
                if (low[next] >= time[node] && parent != -1)
                {
                    isArtPoint[node] = true;
                }
            }
            else
            {
                low[node] = min(low[node], time[next]);
            }
        }
        if (child > 1 && parent == -1)
        {
            isArtPoint[node] = true;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        time.resize(V);
        low.resize(V);
        vector<int> isArtPoint(V, false), vis(V, false), ans;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, isArtPoint);
            }
            if (isArtPoint[i])
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends