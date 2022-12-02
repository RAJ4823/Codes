//? https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
//? https://leetcode.com/problems/number-of-enclaves/submissions/853463657/

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

class Solution
{

private:
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
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        // Checking '1' in border
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (!vis[i][j] && grid[i][j] == 1)
                    {
                        // Using dfs
                        // dfs(i, j, vis, grid);

                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }
            }
        }

        // ==== Using BFS ====
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && !vis[ni][nj] && grid[ni][nj] == 1)
                {
                    q.push({ni, nj});
                    vis[ni][nj] = true;
                }
            }
        }
        // ==== END OF BFS ====

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

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends