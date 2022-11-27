#include <bits/stdc++.h>
using namespace std;

//? TC = O(V + E) , SC = O(N)
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> bfs;
    queue<int> q;

    // Here we taken starting node = 0
    vis[0] = true;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto x : adj[node])
        {
            if (!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
        }
    }
    return bfs;
}

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

        vector<int> ans = bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}