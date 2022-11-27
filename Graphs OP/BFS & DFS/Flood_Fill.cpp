//*https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
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

    //! IDK WHY, But it is giving TLE for some test cases :(
    // void bfs(int si, int sj, int oldColor, int newColor, vector<vector<int>> &grid, vector<vector<int>> &image)
    // {
    //     queue<pair<int, int>> q;
    //     q.push({si, sj});
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     while (!q.empty())
    //     {
    //         int i = q.front().first;
    //         int j = q.front().second;
    //         q.pop();
    //         grid[i][j] = newColor;
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int newi = i + dirx[k];
    //             int newj = j + diry[k];
    //             if (newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] != newColor && image[newi][newj] == oldColor)
    //             {
    //                 q.push({newi, newj});
    //             }
    //         }
    //     }
    // }    

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> grid = image;
        dfs(sr, sc, image[sr][sc], newColor, grid, image);
        // bfs(sr, sc, image[sr][sc], newColor, grid, image);
        return grid;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}