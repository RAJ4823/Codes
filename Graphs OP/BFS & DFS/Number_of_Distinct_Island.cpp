//? https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int i, int j, int basei, int basej, vector<vector<bool>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &v)
    {
        vis[i][j] = true;
        v.push_back({i - basei, j - basej});

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && !vis[ni][nj] && grid[ni][nj] == 1)
                dfs(ni, nj, basei, basej, vis, grid, v);
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    dfs(i, j, i, j, vis, grid, temp);
                    st.insert(temp);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends