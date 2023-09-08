// Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-reach-destination-in-time
 *  RUNTIME: 464 ms
 *  MEMORY: 96.6 MB
 *  DATE: 9-4-2023, 9:50:53 AM
 *
 */

// Solution:

class Solution {
public:
    int N, MAX_TIME;
    int dfs(int node, int time, vector<vector<pair<int,int>>> &adj, vector<vector<int>> &dp, vector<int> &values) {
        if(time < 0) 
            return 1e9;

        if(node == N-1) 
            return values[N-1];
        
        if(dp[time][node] != -1)
            return dp[time][node];
        
        int sum = 1e9;
        for(auto &[nextNode, nextTime]: adj[node]) {
            sum = min(sum, values[node] + dfs(nextNode, time - nextTime, adj, dp, values));
        }
        return dp[time][node] = sum;
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& values) {
        N = values.size();
        vector<vector<pair<int,int>>> adj(N);
        vector<vector<int>> dp(maxTime+1, vector<int> (N, -1));

        for(auto &edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int ans = dfs(0, maxTime, adj, dp, values);
        if(ans == 1e9) return -1;
        return ans;
    }
};
