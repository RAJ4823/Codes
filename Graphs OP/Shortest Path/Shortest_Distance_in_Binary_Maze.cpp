//? https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
//! For leetcode solution - Go down to 79 row number

#include <bits/stdc++.h>
using namespace std;

// TC = O(E logV) where E = n*m*4 and V = n*m so 
//? TC = O(n*m*4*log(n*m)) 

class Solution
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;

        // { mininum-distance , {row , column}};
        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;

        while (!q.empty())
        {
            auto curr = q.front().second;
            int steps = q.front().first;
            q.pop();

            if (curr == destination)
                return steps;

            for (int k = 0; k < 4; k++)
            {
                int ni = curr.first + dx[k];
                int nj = curr.second + dy[k];
                if ((ni >= 0 && nj >= 0 && ni < n && nj < m) && (grid[ni][nj]) && (steps + 1 < dist[ni][nj]))
                {
                    dist[ni][nj] = steps + 1;
                    q.push({steps + 1, {ni, nj}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}
// } Driver Code Ends


//! LEETCODE SOLUTION
//? https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
// class Solution
// {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>> &grid)
//     {
//         int n = grid.size();
//         if (grid[0][0] || grid[n - 1][n - 1])
//             return -1;
//         vector<vector<int>> dist(n, vector<int>(n, 1e9));
//         queue<pair<int, pair<int, int>>> q;
//         q.push({1, {0, 0}});
//         dist[0][0] = 0;
//         while (!q.empty())
//         {
//             int curri = q.front().second.first;
//             int currj = q.front().second.second;
//             int steps = q.front().first;
//             q.pop();
//             if (curri == (n - 1) && currj == (n - 1))
//                 return steps;
//             for (int di = -1; di <= 1; di++)
//             {
//                 for (int dj = -1; dj <= 1; dj++)
//                 {
//                     int ni = curri + di;
//                     int nj = currj + dj;
//                     if (ni == curri && nj == currj)
//                         continue;
//                     if ((ni >= 0 && nj >= 0 && ni < n && nj < n) && (grid[ni][nj] == 0) && (steps + 1 < dist[ni][nj]))
//                     {
//                         dist[ni][nj] = steps + 1;
//                         q.push({steps + 1, {ni, nj}});
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };