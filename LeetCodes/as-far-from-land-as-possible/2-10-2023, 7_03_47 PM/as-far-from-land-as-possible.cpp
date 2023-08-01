// Link: https://leetcode.com/problems/as-far-from-land-as-possible

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: as-far-from-land-as-possible
 *  RUNTIME: 61 ms
 *  MEMORY: 19.7 MB
 *  DATE: 2-10-2023, 7:03:47 PM
 *
 */

// Solution:


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        if(q.size() == 0 || q.size() == m*n) 
            return -1;

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int dist = -1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto &[dx, dy]: dirs) {
                    int x = row + dx;
                    int y = col + dy;

                    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]) continue;
                
                    q.push({x, y});
                    grid[x][y] = 1;
                }
            }
            dist++;
        }
        return dist;

    }
};
