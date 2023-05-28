//? https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int diry[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        int nodes = 1;
        for (int k = 0; k < 8; k++)
        {
            int row = i + dirx[k];
            int col = j + diry[k];
            if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
                continue;

            if (!vis[row][col] && grid[row][col] == 1)
            {
                nodes += dfs(row, col, grid, vis);
            }
        }
        return nodes;
    }

    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    ans = max(ans, dfs(i, j, grid, vis));
                }
            }
        }

        return ans;
    }
};