//? https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> par, size;
    DisjointSet(int n)
    {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int findPar(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = findPar(par[x]);
    }

    void unionBySize(int x, int y)
    {
        int px = findPar(x);
        int py = findPar(y);

        if (px == py)
            return;
        if (size[px] < size[py])
        {
            par[px] = py;
            size[py] += size[px];
        }
        else
        {
            par[py] = px;
            size[px] += size[py];
        }
    }
};

class Solution
{
public:
    int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int diry[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    bool isValid(int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        return true;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);
        set<int> s;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                for (int k = 0; k < 8; k++)
                {
                    int row = i + dirx[k];
                    int col = j + diry[k];
                    if (isValid(row, col, n, m) && grid[row][col] == 1)
                    {
                        ds.unionBySize(i * m + j, row * m + col);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    s.insert(ds.findPar(i * m + j));
                }
            }
        }

        int ans = 0;
        for (auto &node : s)
        {
            ans = max(ans, ds.size[node]);
        }
        return ans;
    }
};