//? https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, par, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
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

    void unionByRank(int x, int y)
    {
        int px = findPar(x);
        int py = findPar(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            par[px] = py;
        else if (rank[px] > rank[py])
            par[py] = px;
        else
        {
            par[py] = px;
            rank[px]++;
        }
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

    bool hasSamePar(int x, int y)
    {
        return findPar(x) == findPar(y);
    }

    int countComponents()
    {
        int cnt = 0;
        for (int i = 0; i < par.size(); i++)
        {
            if (par[i] == i)
                cnt++;
        }
        return cnt;
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds(n);

        int extraEdges = 0;
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (ds.hasSamePar(u, v))
                extraEdges++;
            else
                ds.unionBySize(u, v);
        }
        int requiredEdges = ds.countComponents() - 1;
        if (requiredEdges <= extraEdges)
            return requiredEdges;
        return -1;
    }
};