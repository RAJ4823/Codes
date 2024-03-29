// Link: https://leetcode.com/problems/surrounded-regions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: surrounded-regions
 *  RUNTIME: 29 ms
 *  MEMORY: 10.1 MB
 *  DATE: 12-2-2022, 6:29:31 PM
 *
 */

// Solution:

class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &mat)
    {
        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 && ni < mat.size() && nj < mat[0].size() && !vis[ni][nj] && mat[ni][nj] == 'O')
                dfs(ni, nj, vis, mat);
        }
    }

public:
    void solve(vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse the row
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, vis, mat);
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
                dfs(n - 1, j, vis, mat);
        }

        // Traverse the col
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, vis, mat);
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
                dfs(i, m - 1, vis, mat);
        }

        // Changing 'O' to 'X' which is not visited during dfs
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j])
                    mat[i][j] = 'X';
            }
        }
    }
};
