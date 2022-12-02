//? https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
//? https://leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

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
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
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
        return mat;
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
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends