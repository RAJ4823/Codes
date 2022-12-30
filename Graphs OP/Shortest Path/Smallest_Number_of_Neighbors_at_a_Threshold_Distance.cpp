//? https://practice.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int maxDist)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto &data : edges)
        {
            int u = data[0];
            int v = data[1];
            int w = data[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int city = -1;
        int minCount = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= maxDist)
                    count++;
            }

            if (count <= minCount)
            {
                city = i;
                minCount = count;
            }
        }
        return city;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
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

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends