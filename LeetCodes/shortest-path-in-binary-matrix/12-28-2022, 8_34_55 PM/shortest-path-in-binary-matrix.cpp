// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-path-in-binary-matrix
 *  RUNTIME: 65 ms
 *  MEMORY: 21.9 MB
 *  DATE: 12-28-2022, 8:34:55 PM
 *
 */

// Solution:

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;

        // { mininum-distance , {row , column}};
        q.push({1, {0, 0}});
        dist[0][0] = 0;

        while (!q.empty())
        {
            int curri = q.front().second.first;
            int currj = q.front().second.second;
            int steps = q.front().first;
            q.pop();

            if (curri == (n-1) && currj == (n-1))
                return steps;

            for (int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    int ni = curri + di;
                    int nj = currj + dj;
                    if(ni == curri && nj == currj) continue;
                    if ((ni >= 0 && nj >= 0 && ni < n && nj < n) && (grid[ni][nj] == 0) && (steps + 1 < dist[ni][nj]))
                    {
                        dist[ni][nj] = steps + 1;
                        q.push({steps + 1, {ni, nj}});
                    }
                }
            }
        }
        return -1;
    }
};
