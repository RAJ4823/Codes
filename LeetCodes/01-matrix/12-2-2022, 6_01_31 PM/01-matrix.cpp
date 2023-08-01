// Link: https://leetcode.com/problems/01-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 01-matrix
 *  RUNTIME: 198 ms
 *  MEMORY: 33.6 MB
 *  DATE: 12-2-2022, 6:01:31 PM
 *
 */

// Solution:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<vector<int>> dist(n, vector<int> (m));
        queue<pair<pair<int,int>, int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            dist[row][col] = steps;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr>=0 && nc>=0 && nr < n && nc < m && !vis[nr][nc])
                {
                    q.push({{nr,nc}, steps+1});
                    vis[nr][nc] = true;
                }
            }
        }
        return dist;
    }
};
