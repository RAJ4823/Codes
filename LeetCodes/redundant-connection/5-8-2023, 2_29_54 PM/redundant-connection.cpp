// Link: https://leetcode.com/problems/redundant-connection

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: redundant-connection
 *  RUNTIME: 9 ms
 *  MEMORY: 8.7 MB
 *  DATE: 5-8-2023, 2:29:54 PM
 *
 */

// Solution:

class DisjointSet {
private:
    vector<int> par, size;
public:
    DisjointSet(int n) {
        par.resize(n, -1);
        size.resize(n, 0);
    }

    int findPar(int x) {
        if(par[x] == -1) return x;
        return par[x] = findPar(par[x]);
    }

    void Union(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return;
        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        }  else {
            par[py] = px;
            size[px] += size[py];
        }
    }

    bool areSame(int x, int y) {
        return findPar(x) == findPar(y); 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto &edge: edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            if(ds.areSame(u, v)) {
                return {u+1, v+1};
            }
            else {
                ds.Union(u, v);
            }
        }
        return {};
    }
};
