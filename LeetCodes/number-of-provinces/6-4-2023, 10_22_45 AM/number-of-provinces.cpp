// Link: https://leetcode.com/problems/number-of-provinces

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-provinces
 *  RUNTIME: 25 ms
 *  MEMORY: 13.6 MB
 *  DATE: 6-4-2023, 10:22:45 AM
 *
 */

// Solution:


class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &mat) {
        vis[node] = true;
        for(int j=0; j<vis.size(); j++) {
            if(node == j) continue;
            if(!vis[j] && mat[node][j] == 1) {
                dfs(j, vis, mat);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size(), cnt = 0;
        vector<int> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;
                dfs(i, vis, mat);
            }
        }
        return cnt;
    }
};
