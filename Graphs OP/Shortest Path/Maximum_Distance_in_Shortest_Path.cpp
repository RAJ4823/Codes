//? https://practice.geeksforgeeks.org/problems/alex-travelling/1
//? https://leetcode.com/problems/network-delay-time/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<vector<int>> &flights, int n, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto &data : flights)
        {
            int u = data[0] - 1;
            int v = data[1] - 1;
            int w = data[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> minDist(n, 1e9);
        int source = k - 1;

        pq.push({0, source});
        minDist[source] = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &data : adj[node])
            {
                int neigh = data.first;
                int weight = data.second;
                int newDist = dist + weight;

                if (newDist < minDist[neigh])
                {
                    minDist[neigh] = newDist;
                    pq.push({newDist, neigh});
                }
            }
        }

        int maxDist = 0;
        for (int i = 0; i < n; i++)
            maxDist = max(maxDist, minDist[i]);
        if (maxDist == 1e9)
            return -1;
        return maxDist;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size, vector<int>(3));
        for (int i = 0; i < size; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i] = temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends