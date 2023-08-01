// Link: https://leetcode.com/problems/number-of-provinces

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-provinces
 *  RUNTIME: 61 ms
 *  MEMORY: 13.7 MB
 *  DATE: 1-6-2023, 6:17:22 PM
 *
 */

// Solution:


int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

class Solution {
public:
    void dfs(int i, vector<vector<int>>& mat, vector<bool>& vis) {
        vis[i] = true;
        for (int j = 0; j < vis.size(); j++) {
            if (i != j &&!vis[j] && mat[i][j]) {
                dfs(j, mat, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < vis.size(); i++) {
            if(!vis[i]) {
                count++;
                dfs(i, mat, vis);
            }
        }
        return count;
    }
};
