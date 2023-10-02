// Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-safest-path-in-a-grid
 *  RUNTIME: 847 ms
 *  MEMORY: 125.7 MB
 *  DATE: 9-16-2023, 10:20:05 AM
 *
 */

// Solution:

class Solution
{
public:
// Fill grid cells with minimum manhattan distance from every thief
    vector<vector<int>> safeness;
    int dirs[5] = {-1, 0, 1, 0, -1};

    void fill_safeness(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safeness[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k=0; k<4; k++)
            {
                int i = x + dirs[k];
                int j = y + dirs[k+1];
                if (i < 0 || j < 0 || i >= n || j >= n || safeness[i][j] <= safeness[x][y] + 1)
                    continue;
                q.push({i, j});
                safeness[i][j] = 1 + safeness[x][y];
            }
        }
    }

    // find maximum safeness
    int find(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({safeness[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty())
        {
            int val = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int k=0; k<4; k++)
            {
                int i = x + dirs[k];
                int j = y + dirs[k+1];
                if (i < 0 || j < 0 || i >= n || j >= n || vis[i][j])
                    continue;

                vis[i][j] = true;
                safeness[i][j] = min(safeness[i][j], safeness[x][y]);
                pq.push({safeness[i][j], {i, j}});
            }
        }
        return safeness[n-1][n-1];
    }   

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        safeness.resize(n, vector<int>(n, 1601));
        fill_safeness(grid);
        return find(grid);
    }
};
