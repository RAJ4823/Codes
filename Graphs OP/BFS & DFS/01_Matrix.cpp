//? https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        // vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<int>> dist(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            dist[row][col] = steps;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = row + dx[k];
                int nc = col + dy[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] != -1)
                {
                    q.push({{nr, nc}, steps + 1});
                    mat[nr][nc] = -1;
                }
            }
        }
        return dist;
    }
};