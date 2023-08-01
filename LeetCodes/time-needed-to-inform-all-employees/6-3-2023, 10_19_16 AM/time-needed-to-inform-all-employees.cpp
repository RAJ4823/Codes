// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: time-needed-to-inform-all-employees
 *  RUNTIME: 317 ms
 *  MEMORY: 124.1 MB
 *  DATE: 6-3-2023, 10:19:16 AM
 *
 */

// Solution:

class Solution {
public:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &time) {
        vis[node] = true;
        int currSum = time[node], childSum = 0;
        for(auto &next: adj[node]) {
            if(!vis[next]) {
                childSum = max(childSum, dfs(next, vis, adj, time));
            }
        }
        return currSum + childSum;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, false);
        
        int source = 0;
        for(int i=0; i<n; i++) {
            if(manager[i] == -1) {
                source = i;
            } else {
                adj[manager[i]].push_back(i);
            }
        }

        int ans = dfs(source, vis, adj, informTime);
        return ans;
    }
};
