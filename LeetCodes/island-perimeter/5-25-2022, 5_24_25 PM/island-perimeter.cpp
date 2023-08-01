// Link: https://leetcode.com/problems/island-perimeter

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: island-perimeter
 *  RUNTIME: 178 ms
 *  MEMORY: 96.6 MB
 *  DATE: 5-25-2022, 5:24:25 PM
 *
 */

// Solution:

#define f(i, n) for (int i = 0; i < (n); i++)
class Solution {
public:
int dfs(int i, int j, vector<vector<int>> &grid)
{
    int perimeter = 0;

    if (i < 0 || j < 0)
        return 1;
    if (i >= grid.size() || j >= grid[0].size())
        return 1;
    if (grid[i][j] == 0)
        return 1;
    if (grid[i][j] == 1)
    {
        grid[i][j] = -1;
        perimeter += dfs(i - 1, j, grid);
        perimeter += dfs(i + 1, j, grid);
        perimeter += dfs(i, j - 1, grid);
        perimeter += dfs(i, j + 1, grid);
    }
    return perimeter;
}
    
    int islandPerimeter(vector<vector<int>> &grid)
{
    vector<vector<bool>> vis;
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    f(i, n)
        f(j, m) if (grid[i][j] == 1)
            ans += dfs(i, j, grid);
    return ans;
}

};
