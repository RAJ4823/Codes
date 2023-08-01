// Link: https://leetcode.com/problems/redundant-connection-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: redundant-connection-ii
 *  RUNTIME: 14 ms
 *  MEMORY: 9.5 MB
 *  DATE: 5-8-2023, 7:24:32 PM
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1, -1);

        int WE1 = -1, WE2 = -1;
        //WE1 = Removed Edge which has two parents
        //WE2 = Edge which creates cycle  
        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if(par[v] == -1) {
                par[v] = u;
            } else {
                WE1 = i;
                break;
            }
            
        }
        DisjointSet ds(n+1);

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(i == WE1) 
                continue;

            if(ds.areSame(u, v)) {
                WE2 = i;
                break;
            }
            else {
                ds.Union(u, v);
            }
        }

        if(WE1 == -1)
            return edges[WE2];

        if(WE2 == -1)
            return edges[WE1];

        int v = edges[WE1][1];
        int u = par[v];
        return {u, v};
    }
};
