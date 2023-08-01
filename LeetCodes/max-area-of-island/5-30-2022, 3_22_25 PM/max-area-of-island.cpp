// Link: https://leetcode.com/problems/max-area-of-island

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-area-of-island
 *  RUNTIME: 32 ms
 *  MEMORY: 23.3 MB
 *  DATE: 5-30-2022, 3:22:25 PM
 *
 */

// Solution:

#define f(i, n) for (int i = 0; i < (n); i++)
class Solution {
public:
    void dfs(int i, int j, int &count, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return;
    if (grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    count++;

    dfs(i + 1, j, count, grid);
    dfs(i - 1, j, count, grid);
    dfs(i, j + 1, count, grid);
    dfs(i, j - 1, count, grid);
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int ans = 0, count = 0;
    f(i, grid.size())
    {
        f(j, grid[0].size())
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, count, grid);
                ans = max(ans, count);
                count = 0;
            }
        }
    }
    return ans;
}
};
