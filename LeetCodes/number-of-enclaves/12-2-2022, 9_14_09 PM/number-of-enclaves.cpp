// Link: https://leetcode.com/problems/number-of-enclaves

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-enclaves
 *  RUNTIME: 178 ms
 *  MEMORY: 30.6 MB
 *  DATE: 12-2-2022, 9:14:09 PM
 *
 */

// Solution:

class Solution {

private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && !vis[ni][nj] && grid[ni][nj] == 1)
                dfs(ni, nj, vis, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Checking '1' in border
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (!vis[i][j] && grid[i][j] == 1)
                        dfs(i, j, vis, grid);
                }
            }
        }

        // Counting not visited '1' in grid
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};
