// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-stones-removed-with-same-row-or-column
 *  RUNTIME: 43 ms
 *  MEMORY: 18.4 MB
 *  DATE: 5-27-2023, 5:23:28 PM
 *
 */

// Solution:

class DisjointSet
{
private:
    vector<int> par, size;

public:
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0;
        for(auto &x: stones) {
            n = max(n, x[0] + 1);
            m = max(m, x[1] + 1);
        }
        
        DisjointSet ds(n + m);
        unordered_set<int> rc;
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
