// Link: https://leetcode.com/problems/maximal-network-rank

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximal-network-rank
 *  RUNTIME: 45 ms
 *  MEMORY: 28.3 MB
 *  DATE: 8-18-2023, 10:43:41 AM
 *
 */

// Solution:

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        vector<vector<bool>> adj(n, vector<bool> (n, false));
        for(auto &edge: roads) {
            deg[edge[0]]++;
            deg[edge[1]]++;
            adj[edge[0]][edge[1]] = true;
            adj[edge[1]][edge[0]] = true;
        }
        int maxDeg = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                maxDeg = max(maxDeg, deg[i] + deg[j] - adj[i][j]);
            }
        }
        return maxDeg;
    }
};
