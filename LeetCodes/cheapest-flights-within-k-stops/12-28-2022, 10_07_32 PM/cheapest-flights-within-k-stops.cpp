// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: cheapest-flights-within-k-stops
 *  RUNTIME: 25 ms
 *  MEMORY: 12.9 MB
 *  DATE: 12-28-2022, 10:07:32 PM
 *
 */

// Solution:

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adj[n]; // to store {node, price}
        for (auto &data : flights)
            adj[data[0]].push_back({data[1], data[2]});

        queue<pair<int, pair<int, int>>> q; // to store {stops, {node, price}};
        vector<int> minPrice(n, 1e9);       // to store minimum prices to reach node i

        q.push({0, {src, 0}}); // Initially stops and price will be 0 for source
        minPrice[src] = 0;

        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int priceToReachNode = q.front().second.second;
            q.pop();

            if (stops > K)
                continue;
            for (auto &x : adj[node])
            {
                int neigh = x.first;
                int priceBetweenNodeAndNeigh = x.second;
                int newPrice = priceBetweenNodeAndNeigh + priceToReachNode;

                //If newPrice is less then previousPriceToReachNeigh and requiredStops <= K then update it
                if (newPrice < minPrice[neigh] && stops <= K)
                {
                    minPrice[neigh] = newPrice;
                    q.push({stops + 1, {neigh, newPrice}});
                }
            }
        }
        if (minPrice[dst] == 1e9)
            return -1;
        return minPrice[dst];
    }
};
