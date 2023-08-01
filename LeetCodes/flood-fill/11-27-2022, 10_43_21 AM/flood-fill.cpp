// Link: https://leetcode.com/problems/flood-fill

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flood-fill
 *  RUNTIME: 21 ms
 *  MEMORY: 14 MB
 *  DATE: 11-27-2022, 10:43:21 AM
 *
 */

// Solution:

class Solution {
public:
    
  int dirx[4] = {-1, 0, 1, 0};
    int diry[4] = {0, 1, 0, -1};

    void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>> &grid, vector<vector<int>> &image)
    {
        grid[i][j] = newColor;
        for (int k = 0; k < 4; k++)
        {
            int newi = i + dirx[k];
            int newj = j + diry[k];
            if (newi >= 0 && newi < grid.size() && newj >= 0 && newj < grid[0].size() && grid[newi][newj] != newColor && image[newi][newj] == oldColor)
                dfs(newi, newj, oldColor, newColor, grid, image);
        }
    }

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<vector<int>> grid = image;
    dfs(sr, sc, image[sr][sc], newColor, grid, image);
    return grid;
}

};
