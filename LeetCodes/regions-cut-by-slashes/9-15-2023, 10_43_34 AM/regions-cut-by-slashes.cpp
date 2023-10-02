// Link: https://leetcode.com/problems/regions-cut-by-slashes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: regions-cut-by-slashes
 *  RUNTIME: 8 ms
 *  MEMORY: 10.2 MB
 *  DATE: 9-15-2023, 10:43:34 AM
 *
 */

// Solution:

class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) 
            par[i] = i;
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    bool merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) 
           return true;

        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }

        return false;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows + 1, m = cols + 1;

        DisjointSet ds(n * m);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || i == rows || j == 0 || j == cols) {
                    int node = i * n + j;
                    if(node > 0) {
                        ds.merge(0, node);
                    }
                }
            }
        }

        int ans = 1;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == ' ') continue;

                int x = (i * n) + j + (grid[i][j] == '/');
                int y = (i * n) + j + n + (grid[i][j] == '\\');
                
                ans += ds.merge(x, y);
            }
        }
        return ans;
    }
};
