//* https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include <bits/stdc++.h>
using namespace std;

//? TC = O(n * m * 9) , SC = O(n * m)
class Solution
{
private:
    void bfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //! Neighbours = All 8 direction
            //? (i-1,j-1) (i-1,j) (i-1, j+1) (i, j-1) (i, j) (i, j+1) (i+1, j-1) (i+1, j) (i+1, j+1)

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ii = row + di;
                    int jj = col + dj;
                    if ((ii >= 0 && ii < n) && (jj >= 0 && jj < m) && (grid[ii][jj] == '1' && !vis[ii][jj]))
                    {
                        vis[ii][jj] = true;
                        q.push({ii, jj});
                    }
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        vis[i][j] = true;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int ii = i + di;
                int jj = j + dj;
                if ((ii >= 0 && ii < grid.size()) && (jj >= 0 && jj < grid[0].size()) && (grid[ii][jj] == '1' && !vis[ii][jj]))
                {
                    dfs(ii, jj, vis, grid);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    bfs(i, j, vis, grid);
                    // dfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
