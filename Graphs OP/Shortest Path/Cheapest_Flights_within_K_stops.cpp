//? https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
//? https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
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

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        int edge;
        cin >> edge;
        vector<vector<int>> flights;

        for (int i = 0; i < edge; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }

        int src, dst, k;
        cin >> src >> dst >> k;
        Solution obj;
        cout << obj.CheapestFLight(n, flights, src, dst, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends