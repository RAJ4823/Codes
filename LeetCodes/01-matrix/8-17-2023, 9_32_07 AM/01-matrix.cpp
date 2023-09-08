// Link: https://leetcode.com/problems/01-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 01-matrix
 *  RUNTIME: 54 ms
 *  MEMORY: 30.4 MB
 *  DATE: 8-17-2023, 9:32:07 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int> (m, -1));

        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(mat[i][j] == 0) 
                    q.push({i, j}), dist[i][j] = 0;
        
        int steps = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++) {
                int row = x + dirs[k];
                int col = y + dirs[k+1];

                if(row >= 0 && col >= 0 && row < n && col < m && dist[row][col] == -1) {
                    q.push({row, col});
                    dist[row][col] = dist[x][y] + 1;
                }
            }
        }
        
        return dist;
    }
};
