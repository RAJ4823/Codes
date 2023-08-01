// Link: https://leetcode.com/problems/swim-in-rising-water

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: swim-in-rising-water
 *  RUNTIME: 57 ms
 *  MEMORY: 13.4 MB
 *  DATE: 5-2-2023, 9:55:21 AM
 *
 */

// Solution:

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, INT_MAX));
        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0}, grid[0][0]});
        vis[0][0] = grid[0][0];
        int dist[5] = {-1,0,1,0,-1};
        int ans = n*n - 1;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            if(row == n-1 && col == n-1) {
                cout << time << ' ';
                ans = min(ans, time);
            }

            for(int k=0; k<4; k++) {
                int x = row + dist[k];
                int y = col + dist[k+1];

                if(x < 0 || y < 0 || x >= n || y >= n)
                    continue;
                
                int newTime = max(time, grid[x][y]) ;
                if(vis[x][y] > newTime) {
                    vis[x][y] = newTime;
                    q.push({{x, y}, newTime});
                }
            }
        }
        return ans;
    }
};
