// Link: https://leetcode.com/problems/network-delay-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: network-delay-time
 *  RUNTIME: 112 ms
 *  MEMORY: 39.9 MB
 *  DATE: 12-30-2022, 7:21:30 PM
 *
 */

// Solution:

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<pair<int, int>> adj[n];
        for (auto &data : times)
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
        {
            maxDist = max(maxDist, minDist[i]);
        }
        if (maxDist == 1e9)
            return -1;
        return maxDist;
    }
};
