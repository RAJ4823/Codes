//? https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1


#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<pair<int, int>> adj[n];
        for (auto &data : roads)
        {
            int u = data[0];
            int v = data[1];
            int w = data[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> minDist(n, 1e9);
        vector<int> ways(n, 0);

        pq.push({0, 0});
        minDist[0] = 0;
        ways[0] = 1;       // To store the number of ways node 'i' can be reached

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &x : adj[node])
            {
                int neigh = x.first;
                int weight = x.second;
                int newDist = dist + weight;

                // When you arrive at node for first time
                if (newDist < minDist[neigh])
                {
                    minDist[neigh] = newDist;
                    pq.push({newDist, neigh});
                    ways[neigh] = ways[node];
                }
                else if (newDist == minDist[neigh])
                {
                    // When you arrive at node for another time
                    ways[neigh] = (ways[neigh] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends