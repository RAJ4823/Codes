//* https://practice.geeksforgeeks.org/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (auto x : adj[node])
        if (!vis[x])
            dfs(x, adj, vis);
}

int numProvinces(vector<vector<int>> &adjMat, int V)
{
    vector<bool> vis(V, false);
    vector<int> adjList[V];
    int count = 0;

    //Converting AdjMatrix to AdjList
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adjMat[i][j] == 1 && i != j)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjList, vis);
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;
        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        cout << numProvinces(adj, V) << endl;
    }
    return 0;
}