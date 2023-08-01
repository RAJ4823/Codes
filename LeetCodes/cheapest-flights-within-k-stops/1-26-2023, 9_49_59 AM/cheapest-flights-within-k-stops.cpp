// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: cheapest-flights-within-k-stops
 *  RUNTIME: 11 ms
 *  MEMORY: 13 MB
 *  DATE: 1-26-2023, 9:49:59 AM
 *
 */

// Solution:

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> graph[n];
        for (auto &data : flights)  graph[data[0]].push_back({data[1], data[2]});

        queue<pair<int, pair<int, int>>> q;
        vector<int> minp(n, 1e9);      
        q.push({0, {src, 0}}); 
        minp[src] = 0;

        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            if (stops > K)  continue;
            for (auto &x : graph[node])
            {
                int next = x.first;
                int weight = x.second;
                if ((weight + price < minp[next]) && (stops <= K))
                {
                    minp[next] = weight + price;
                    q.push({stops + 1, {next, minp[next]}});
                }
            }
        }
        if (minp[dst] == 1e9) return -1;
        return minp[dst];
    }
};
