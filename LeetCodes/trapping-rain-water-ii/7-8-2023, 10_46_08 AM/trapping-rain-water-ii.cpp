// Link: https://leetcode.com/problems/trapping-rain-water-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: trapping-rain-water-ii
 *  RUNTIME: 76 ms
 *  MEMORY: 13.7 MB
 *  DATE: 7-8-2023, 10:46:08 AM
 *
 */

// Solution:

class Solution {
public:
    int trapRainWater(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, false));
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0; i<m; i++) {
            pq.push({-mat[0][i], {0, i}});
            pq.push({-mat[n-1][i], {n-1, i}});
            vis[0][i] = true;
            vis[n-1][i] = true;
        }

        for(int i=0; i<n; i++) {
            pq.push({-mat[i][0], {i, 0}});
            pq.push({-mat[i][m-1], {i, m-1}});
            vis[i][0] = true;
            vis[i][m-1] = true;
        }

        int ans = 0;
        while(!pq.empty()) {
            int height = -pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int k=0; k<4; k++) {
                int x = row + dirs[k];
                int y = col + dirs[k+1];

                if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y]) {
                    vis[x][y] = true;
                    ans += max(0, height - mat[x][y]);
                    pq.push({min(-height, -mat[x][y]), {x, y}});                    
                }
            }
        }
        return ans;
    }
};
