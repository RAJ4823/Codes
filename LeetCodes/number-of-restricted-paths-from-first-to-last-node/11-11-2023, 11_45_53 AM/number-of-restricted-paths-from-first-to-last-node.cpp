// Link: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-restricted-paths-from-first-to-last-node
 *  RUNTIME: 480 ms
 *  MEMORY: 156 MB
 *  DATE: 11-11-2023, 11:45:53 AM
 *
 */

// Solution:

class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> adj;
    long long mod = 1e9 + 7;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        } 

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<long long> minDist(n+1, INT_MAX), count(n+1, 0);
        pq.push({0, n});
        minDist[n] = 0;
        count[n] = 1;
        
        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if(dist > minDist[node]) 
                continue;

            for(auto &x: adj[node]) {
                int next = x.first;
                int weight = x.second;
                if(dist + weight < minDist[next]) {
                    minDist[next] = dist+weight;
                    pq.push({minDist[next], next});
                }
                if(dist > minDist[next]) {
                    count[node] = (count[node] + count[next]) % mod;
                }
            }
        }
        return count[1];
    }
};
