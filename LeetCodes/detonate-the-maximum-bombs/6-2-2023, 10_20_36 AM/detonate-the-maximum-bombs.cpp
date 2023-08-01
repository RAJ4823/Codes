// Link: https://leetcode.com/problems/detonate-the-maximum-bombs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: detonate-the-maximum-bombs
 *  RUNTIME: 125 ms
 *  MEMORY: 18.1 MB
 *  DATE: 6-2-2023, 10:20:36 AM
 *
 */

// Solution:

class Solution {
public:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &adj) {
        vis[node] = true;
        int cnt = 1;
        for(auto &next: adj[node]) {
            if(!vis[next]) {
                cnt += dfs(next, vis, adj);
            }
        }
        return cnt;
    }
    bool isInRange(int i, int j, vector<vector<int>>& bombs) {
        if(i == j) return false;

        long long x1 = bombs[i][0], x2 = bombs[j][0];
        long long y1 = bombs[i][1], y2 = bombs[j][1];
        long long r1 = bombs[i][2], r2 = bombs[j][2];
        long long dist = (((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
        if(dist <= r1*r1) return true;
        return false;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isInRange(i, j, bombs)) {
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            vector<int> vis(n, false);
            ans = max(ans, dfs(i, vis, adj));
        }
        return ans;
    }
};
