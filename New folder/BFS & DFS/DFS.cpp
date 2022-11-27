
#include <bits/stdc++.h>
using namespace std;

//? TC = O(V + E) , SC = O(N)
void dfs(int node, vector<int> &arr, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    arr.push_back(node);

    for (auto x : adj[node])
        if (!vis[x])
            dfs(x, arr, vis, adj);
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    vector<int> arr;
    dfs(0, arr, vis, adj);
    return arr;
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

        vector<int> ans = dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
