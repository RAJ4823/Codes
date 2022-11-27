//* https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        //  {{row, column}, time}
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];
        int cntFresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }

                if (grid[i][j] == 1)
                    cntFresh++;
            }
        }

        int tm = 0;
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, 1, 0, -1};
        int cnt = 0;

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
            return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends