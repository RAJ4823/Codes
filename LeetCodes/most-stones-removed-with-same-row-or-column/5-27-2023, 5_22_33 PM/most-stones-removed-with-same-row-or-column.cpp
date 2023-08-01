// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-stones-removed-with-same-row-or-column
 *  RUNTIME: 53 ms
 *  MEMORY: 19.5 MB
 *  DATE: 5-27-2023, 5:22:33 PM
 *
 */

// Solution:

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
            if (par[i] == i) {
                cout << i << ' ';
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;
        for(auto &x: stones) {
            n = max(n, x[0] + 1);
            m = max(m, x[1] + 1);
        }
        
        DisjointSet ds(n + m);
        set<int> rc;
        for(auto &x: stones) {
            int row = x[0];
            int col = x[1] + n;
            rc.insert(row);
            rc.insert(col);
            ds.unionBySize(row, col);
        }

        int totalStones = stones.size();
        int totalComponents = 0;
        for(auto &x: rc) {
            if(ds.findPar(x) == x) {
                totalComponents++;
            }
        }
        return totalStones - totalComponents;
    }
};
