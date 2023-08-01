// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
 *  RUNTIME: 85 ms
 *  MEMORY: 16.4 MB
 *  DATE: 12-30-2022, 7:07:24 PM
 *
 */

// Solution:

class Solution {
private:
    vector<int> dijkstra(int source, vector<pair<int,int>> adj[], int n) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> minDist(n, 1e9);
        
        pq.push({0, source});
        minDist[source] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto &data: adj[node]) {
                int neigh = data.first;
                int weight = data.second;
                int newDist = dist + weight;
                
                if(newDist < minDist[neigh]) {
                    minDist[neigh] = newDist;
                    pq.push({newDist, neigh});
                }
            }
        }
        return minDist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int maxDist) {
        vector<vector<int>> dist(n, vector<int> (n));
        vector<pair<int,int>> adj[n];
        for(auto &data: edges) {
            int u = data[0];
            int v = data[1];
            int w = data[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Dijkstra's Algorithm
        for(int i=0; i<n; i++) {
            dist[i] = dijkstra(i, adj, n);
        }
        
        int city = -1;
        int minCount = INT_MAX;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j =0; j<n; j++) {
                if(dist[i][j] <= maxDist)
                    count++;
            }
            
            if(count <= minCount) {
                city = i;
                minCount = count;
            }
        }
        return city;
    }
};
