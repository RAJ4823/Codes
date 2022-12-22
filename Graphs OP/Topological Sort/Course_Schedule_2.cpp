//? https://practice.geeksforgeeks.org/problems/course-schedule/
//? https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int V, int m, vector<vector<int>> edges)
    {
        vector<int> adj[V];
        for (auto &x : edges)
            adj[x[1]].push_back(x[0]);

        //! Kahn's Algorithm for finding topological sort: start
        vector<int> ind(V, 0); // indegree
        for (int i = 0; i < V; i++)
            for (auto &x : adj[i])
                ind[x]++;

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (ind[i] == 0)
                q.push(i);

        vector<int> topo; // to store nodes in topo order
        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto &x : adj[node])
            {
                ind[x]--;
                if (ind[x] == 0)
                    q.push(x);
            }
        }
        //! Algo end

        if (topo.size() == V)
            return topo;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            prerequisites.push_back({u, v});
        }

        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);

        Solution obj;
        vector<int> res = obj.findOrder(n, m, prerequisites);
        if (!res.size())
            cout << "No Ordering Possible" << endl;
        else
            cout << check(n, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends