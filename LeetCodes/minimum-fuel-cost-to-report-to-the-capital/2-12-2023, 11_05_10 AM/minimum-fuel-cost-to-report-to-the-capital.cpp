// Link: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-fuel-cost-to-report-to-the-capital
 *  RUNTIME: 603 ms
 *  MEMORY: 191.4 MB
 *  DATE: 2-12-2023, 11:05:10 AM
 *
 */

// Solution:

class Solution {
public:
    long long fuel;

    long long dfs(int node, int parent, vector<vector<int>>& adj, int& seats) {
        int count = 1;
        for (auto& child : adj[node]) {
            if (child != parent) {
                count += dfs(child, node, adj, seats);
            }
        }

        if (node != 0) {
            fuel += ceil((double)count / seats);
        }
        return count;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
}; 
